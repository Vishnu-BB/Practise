#include <iostream>
#include <vector>
class Tensor {
    public:
        int rows, cols;
        std::vector<float> data;

        Tensor(int r, int c) : rows(r), cols(c), data(r*c, 0.0f) {}
        float& operator()(int i, int j) {
            return data[i*cols + j];
        }
        const float& operator()(int i, int j) const {
            return data[i*cols + j];
        }
};

Tensor add(const Tensor& A, const Tensor& B) {
    Tensor Y(A.rows, A.cols);
    for (size_t i = 0; i < A.data.size(); ++i) {
        Y.data[i] = A.data[i] + B.data[i];
    }
    return Y;
}
Tensor transpose(const Tensor& X) {
    Tensor Y(X.cols, X.rows);
    for (size_t i = 0; i < X.rows; ++i)
        for (size_t j = 0; j < X.rows; ++j)
            Y(j, i) = X(i, j);
    return Y;
}
int main(){
    Tensor A(2, 3);
    Tensor B(2, 3);
    A(0, 0) = 1.0; A(0, 1) = 2.0; A(0, 2) = 3.0;
    A(1, 0) = 4.0; A(1, 1) = 5.0; A(1, 2) = 6.0;
    B(0, 0) = 10.0; B(0, 1) = 20.0; B(0, 2) = 30.0;
    B(1, 0) = 40.0; B(1, 1) = 50.0; B(1, 2) = 60.0;
    Tensor C = transpose(A); 
    Tensor c = add(C, B);

    for (int i = 0; i < c.rows; ++i) {
        for (int j = 0; j < c.cols; ++j) {
            std::cout << c(i, j) << " ";    
        }
    }
    std::cout << std::endl;
    return 0;    
}