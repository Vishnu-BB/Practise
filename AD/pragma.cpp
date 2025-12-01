#include <iostream>
#include <vector>

int main() {
    constexpr int N = 1024;
    std::vector<float> a(N, 1.0f), b(N, 2.0f), c(N);

    // 1. #pragma loop count(n)
    // Hint the compiler that the loop usually iterates N times
    #pragma loop count(N)
    for(int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }

    // 2. #pragma vector always
    // Force the compiler to vectorize this loop if safe
    #pragma vector always
    for(int i = 0; i < N; ++i) {
        c[i] = a[i] * b[i];
    }

    // 3. #pragma vector align
    // Assert that arrays are aligned to 16-byte boundary (for SSE)
    float* pa = a.data();
    float* pb = b.data();
    float* pc = c.data();
    #pragma vector align
    for(int i = 0; i < N; ++i) {
        pc[i] = pa[i] - pb[i];
    }

    // 4. #pragma novector
    // Ask the compiler NOT to vectorize this loop
    #pragma novector
    for(int i = 0; i < N; ++i) {
        pc[i] = pa[i] / (pb[i] + 1e-6f); // complex or unsafe operation
    }

    // 5. #pragma vector nontemporal
    // Hint that the store to 'c' won’t be reused soon (streaming store)
    #pragma vector nontemporal
    for(int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }

    std::cout << "First element: " << c[0] << std::endl;
    return 0;
}
