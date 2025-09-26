#include <iostream>
#include <cstdint>
#include <cmath>
#include <iomanip>

uint16_t float_to_half(float f) {
    uint32_t x = *(uint32_t*)&f;
    uint32_t sign = (x >> 16) & 0x8000u;
    uint32_t mant = x & 0x007FFFFFu;
    uint32_t exp = (x >> 23) & 0xFFu;

    // NaN or Inf
    if (exp == 0xFFu) {
        if (mant) return (uint16_t)(sign | 0x7E00u); // NaN -> qNaN
        return (uint16_t)(sign | 0x7C00u); // Inf
    }

    int32_t new_exp = int32_t(exp) - 127 + 15; // exponent adjust
    if (new_exp >= 0x1F) { // overflow -> Inf
        return (uint16_t)(sign | 0x7C00u);
    } else if (new_exp <= 0) { // underflow -> subnormals or zero
        if (new_exp < -10) {
            // too small becomes 0
            return (uint16_t)sign;
        }
        // convert to subnormal
        mant = mant | 0x00800000u; // add hidden leading 1
        uint32_t shift = (uint32_t)(1 - new_exp);
        uint32_t mant_rounded = mant >> (shift + 13); // 23 - 10 = 13
        // round (simple)
        uint32_t rem = mant & ((1u << (shift + 13)) - 1u);
        if (rem > (1u << (shift + 12))) mant_rounded++;
        return (uint16_t)(sign | mant_rounded);
    }

    // normal number
    uint32_t mant16 = mant >> 13; // keep top 10 bits of mantissa
    // round-to-nearest (simple)
    uint32_t rem = mant & 0x1FFFu;
    if (rem > 0x1000u) {
        mant16++;
        if (mant16 == 0x400u) { // mantissa overflow -> increment exponent
            mant16 = 0;
            new_exp++;
            if (new_exp >= 0x1F) { // overflow to inf
                return (uint16_t)(sign | 0x7C00u);
            }
        }
    }

    uint16_t result = (uint16_t)(sign | (new_exp << 10) | (mant16 & 0x3FFu));
    return result;
}

float half_to_float(uint16_t h) {
    uint32_t sign = (uint32_t)(h & 0x8000u) << 16;
    uint32_t exp = (h >> 10) & 0x1Fu;
    uint32_t mant = h & 0x3FFu;

    uint32_t f;
    if (exp == 0x1F) {
        // Inf or NaN
        if (mant) {
            f = sign | 0x7F800001u; // quiet NaN
        } else {
            f = sign | 0x7F800000u; // Inf
        }
    } else if (exp == 0) {
        if (mant == 0) {
            // zero
            f = sign;
        } else {
            // subnormal -> normalize
            exp = 1;
            while ((mant & 0x400u) == 0) {
                mant <<= 1;
                exp--;
            }
            mant &= 0x3FFu;
            uint32_t new_exp = (uint32_t)(exp - 1 + (127 - 15));
            uint32_t new_mant = mant << 13;
            f = sign | (new_exp << 23) | new_mant;
        }
    } else {
        uint32_t new_exp = (uint32_t)(exp - 15 + 127);
        uint32_t new_mant = mant << 13;
        f = sign | (new_exp << 23) | new_mant;
    }

    return *(float*)&f;
}

// Utility wrapper types for demo clarity:
struct FP16 {
    uint16_t bits;
    FP16(): bits(0) {}
    FP16(float f) { bits = float_to_half(f); }
    operator float() const { return half_to_float(bits); }
};

// --- model definition ---
// y = sin(x * w) + (x * w)^2
// We'll show:
// - baseline: w_fp32, activations in fp32, grads in fp32
// - mixed: w stored in fp16 (FP16 bits), master_w_fp32 kept; activations stored as FP16 for memory;
//          during forward we compute using fp32 by converting; during backward gradients computed in fp32.

struct BaselineModel {
    float w;    // stored in fp32
    BaselineModel(float w0): w(w0) {}
    // forward: returns y and stores linear activation
    float forward(float x, float &linear_out) {
        linear_out = x * w;
        float s = std::sin(linear_out);
        float sq = linear_out * linear_out;
        float y = s + sq;
        return y;
    }
    // backward: computes gradients wrt w and x given dL/dy (dy)
    void backward(float x, float linear, float dy, float &dw, float &dx) {
        float ds_dlinear = std::cos(linear);
        float dsq_dlinear = 2.0f * linear;
        float dy_dlinear = ds_dlinear + dsq_dlinear;
        dw = dy_dlinear * x;
        dx = dy_dlinear * w;
    }
};

struct MixedPrecisionModel {
    // weight stored as FP16 (memory-efficient)
    FP16 w_fp16;          // storage copy (FP16)
    float w_master_fp32;  // master copy for updates (FP32)

    // we will store activation (linear) as FP16 to illustrate memory savings
    MixedPrecisionModel(float w0) {
        w_master_fp32 = w0;
        w_fp16 = FP16(w0);
    }

    // forward: we convert FP16 weight to FP32 for computation, optionally store activation in FP16
    float forward(float x, FP16 &linear_out_fp16) {
        float w32 = float(w_fp16); // convert stored fp16 -> fp32
        float linear = x * w32;
        // store activation as FP16 to save memory
        linear_out_fp16 = FP16(linear);
        float s = std::sin(linear);
        float sq = linear * linear;
        return s + sq;
    }

    // backward: recompute using fp32 (convert linear back to fp32), compute gradients in fp32
    // we compute grads wrt master weight (fp32). The stored w_fp16 is just storage, update is applied to w_master_fp32.
    void backward(float x, const FP16 &linear_out_fp16, float dy, float &dw_fp32, float &dx_fp32) {
        // Convert activation back to FP32 for stable gradient computation
        float linear = float(linear_out_fp16);
        float ds_dlinear = std::cos(linear);
        float dsq_dlinear = 2.0f * linear;
        float dy_dlinear = ds_dlinear + dsq_dlinear;

        // gradients computed in FP32
        dw_fp32 = dy_dlinear * x;
        dx_fp32 = dy_dlinear * float(w_fp16); // or w_master_fp32 (they should be close)
    }

    // simple SGD step on master FP32 weight, then sync storage FP16 weight
    void sgd_step(float lr, float dw_fp32) {
        w_master_fp32 -= lr * dw_fp32;
        // write back to fp16 storage (simulate saving memory representation)
        w_fp16 = FP16(w_master_fp32);
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(8);

    // Input and initial weight
    float x = 2.0f;
    float w0 = 3.0f;
    float learning_rate = 0.01f;

    // Baseline FP32 model
    BaselineModel baseline(w0);
    float linear_baseline = 0.0f;
    float y_baseline = baseline.forward(x, linear_baseline);
    // Suppose loss L = 0.5 * y^2 (for demo), dL/dy = y
    float dy = y_baseline;
    float dw_b = 0.0f, dx_b = 0.0f;
    baseline.backward(x, linear_baseline, dy, dw_b, dx_b);
    // update
    baseline.w -= learning_rate * dw_b;

    std::cout << "=== Baseline FP32 ===\n";
    std::cout << "y = " << y_baseline << "\n";
    std::cout << "linear (fp32) = " << linear_baseline << "\n";
    std::cout << "dw (fp32) = " << dw_b << ", dx (fp32) = " << dx_b << "\n";
    std::cout << "updated w (fp32 master) = " << baseline.w << "\n\n";

    // Mixed-precision model
    MixedPrecisionModel mp(w0);
    FP16 linear_mp_fp16;
    float y_mp = mp.forward(x, linear_mp_fp16);

    float dw_mp_fp32 = 0.0f, dx_mp_fp32 = 0.0f;
    // same loss L = 0.5 * y^2 => dL/dy = y
    float dy_mp = y_mp;
    mp.backward(x, linear_mp_fp16, dy_mp, dw_mp_fp32, dx_mp_fp32);
    mp.sgd_step(learning_rate, dw_mp_fp32);

    std::cout << "=== Mixed Precision (weights stored in FP16, grads in FP32) ===\n";
    std::cout << "y = " << y_mp << "\n";
    std::cout << "linear (stored fp16 -> recovered fp32) = " << float(linear_mp_fp16) << "\n";
    std::cout << "dw (fp32) = " << dw_mp_fp32 << ", dx (fp32) = " << dx_mp_fp32 << "\n";
    std::cout << "w stored (fp16 bits) = 0x" << std::hex << mp.w_fp16.bits << std::dec << "\n";
    std::cout << "w master (fp32) after update = " << mp.w_master_fp32 << "\n";

    // Compare baseline and mixed after one step (they may differ slightly due to FP16 rounding)
    std::cout << "\n=== Comparison ===\n";
    std::cout << "baseline.w (fp32) = " << baseline.w << "\n";
    std::cout << "mixed.w_master (fp32) = " << mp.w_master_fp32 << "\n";
    std::cout << "difference = " << (baseline.w - mp.w_master_fp32) << "\n";

    return 0;
}
