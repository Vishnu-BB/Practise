#include <iostream>
#include <cmath>
#include <memory>

struct Value {
    double val;     // forward value
    double grad;    // gradient
    bool saved;     // whether we checkpoint or not

    Value(double v=0, bool save=true): val(v), grad(0.0), saved(save) {}
};

// Forward pass (with/without checkpointing)
Value forward(const Value& x, const Value& w, bool checkpoint) {
    // linear = x * w
    Value linear(x.val * w.val, checkpoint); 

    // sin part
    Value s(std::sin(linear.val), checkpoint);

    // square part
    Value sq(linear.val * linear.val, checkpoint);

    // output
    Value y(s.val + sq.val, true);
    return y;
}

// Backward pass (needs recomputation if not saved)
void backward(Value& x, Value& w, bool checkpoint) {
    // Recompute forward if checkpointing disabled
    double linear_val = checkpoint ? (x.val * w.val) : (x.val * w.val);
    double s_val = checkpoint ? std::sin(linear_val) : std::sin(linear_val);
    double sq_val = checkpoint ? (linear_val * linear_val) : (linear_val * linear_val);

    // Gradient of y wrt sin and square
    double dy_ds = 1.0;
    double dy_dsq = 1.0;

    // Grad of sin(linear)
    double ds_dlinear = std::cos(linear_val);

    // Grad of (linear^2)
    double dsq_dlinear = 2 * linear_val;

    // Chain rule
    double dy_dlinear = dy_ds * ds_dlinear + dy_dsq * dsq_dlinear;

    // Grad wrt x and w
    x.grad = dy_dlinear * w.val;
    w.grad = dy_dlinear * x.val;
}

int main() {
    Value x(2.0); // input
    Value w(3.0); // weight

    // Case 1: Naive (store everything)
    auto y1 = forward(x, w, true);
    backward(x, w, true);
    std::cout << "[Naive] y=" << y1.val << " dx=" << x.grad << " dw=" << w.grad << "\n";

    // Reset grads
    x.grad = w.grad = 0;

    // Case 2: With checkpointing (don’t store intermediates)
    auto y2 = forward(x, w, false);
    backward(x, w, false);
    std::cout << "[Checkpoint] y=" << y2.val << " dx=" << x.grad << " dw=" << w.grad << "\n";

    return 0;
}
