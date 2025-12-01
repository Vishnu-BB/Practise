#include <iostream>
#include <memory>

struct Value {
    float data;
    float grad;
    std::string name;

    Value(float d, std::string n) : data(d), grad(0.0f), name(n) {}
};

// Computation graph nodes
struct Computation {
    std::shared_ptr<Value> x, w, b;
    std::shared_ptr<Value> linear, out, y;

    void forward() {
        linear = std::make_shared<Value>(x->data * w->data, "linear");
        out = std::make_shared<Value>(linear->data + b->data, "out");
        y = std::make_shared<Value>(out->data * out->data, "y");
        std::cout << "[Forward] y = " << y->data << std::endl;
    }

    void backward() {
        // start from dy/dy = 1
        y->grad = 1.0f;

        // grad wrt out: dy/dout = 2*out
        out->grad = 2 * out->data * y->grad;

        // --- careful deletion: free y after use
        y.reset();

        // grad wrt linear, b
        linear->grad = 1 * out->grad;
        b->grad = 1 * out->grad;

        // --- careful deletion: free out after use
        out.reset();

        // grad wrt x, w
        x->grad = w->data * linear->grad;
        w->grad = x->data * linear->grad;

        // --- careful deletion: free linear after use
        linear.reset();
    }
};

int main() {
    // Inputs
    auto x = std::make_shared<Value>(2.0f, "x");
    auto w = std::make_shared<Value>(3.0f, "w");
    auto b = std::make_shared<Value>(1.0f, "b");

    Computation comp;
    comp.x = x;
    comp.w = w;
    comp.b = b;

    comp.forward();
    comp.backward();

    std::cout << "Gradient wrt x: " << x->grad << std::endl;
    std::cout << "Gradient wrt w: " << w->grad << std::endl;
    std::cout << "Gradient wrt b: " << b->grad << std::endl;

    return 0;
}
