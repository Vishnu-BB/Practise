// #include <cstdio>
// #include <cstdlib>
// #include <cuda_runtime.h>

// /* ------------------------------------------------------------------
//  * Error checking macro – prints a message and exits on failure
//  * ------------------------------------------------------------------ */
// #define CHECK_CUDA(call)                                                \
//     do {                                                                \
//         cudaError_t err = (call);                                       \
//         if (err != cudaSuccess) {                                       \
//             fprintf(stderr, "CUDA error in %s (%s:%d): %s\n",           \
//                     #call, __FILE__, __LINE__, cudaGetErrorString(err));\
//             exit(EXIT_FAILURE);                                         \
//         }                                                               \
//     } while (0)

// /* ------------------------------------------------------------------
//  * Kernel: Each thread computes one element of C = A × B
//  * ------------------------------------------------------------------ */
// __global__ void matmul_kernel(const float *A, const float *B, float *C,
//                               int N)
// {
//     /* Compute row and column index of C that this thread will work on */
//     int row = blockIdx.y * blockDim.y + threadIdx.y;
//     int col = blockIdx.x * blockDim.x + threadIdx.x;

//     if (row < N && col < N) {
//         float sum = 0.0f;
//         /* Standard dot product */
//         for (int k = 0; k < N; ++k)
//             sum += A[row * N + k] * B[k * N + col];
//         C[row * N + col] = sum;
//     }
// }

// /* ------------------------------------------------------------------
//  * Main function – host code
//  * ------------------------------------------------------------------ */
// int main(void)
// {
//     /* Matrix size (NxN) */
//     const int N = 1024;              // you can change this to any value
//     const size_t bytes = N * N * sizeof(float);

//     /* Allocate host memory */
//     float *h_A = (float *)malloc(bytes);
//     float *h_B = (float *)malloc(bytes);
//     float *h_C = (float *)malloc(bytes);

//     /* Initialize matrices with some values (e.g., A=1, B=2) */
//     for (int i = 0; i < N * N; ++i) {
//         h_A[i] = 1.0f;               // or any pattern you like
//         h_B[i] = 2.0f;
//     }

//     /* Allocate device memory */
//     float *d_A, *d_B, *d_C;
//     CHECK_CUDA(cudaMalloc((void **)&d_A, bytes));
//     CHECK_CUDA(cudaMalloc((void **)&d_B, bytes));
//     CHECK_CUDA(cudaMalloc((void **)&d_C, bytes));

//     /* Copy input matrices from host to device */
//     CHECK_CUDA(cudaMemcpy(d_A, h_A, bytes, cudaMemcpyHostToDevice));
//     CHECK_CUDA(cudaMemcpy(d_B, h_B, bytes, cudaMemcpyHostToDevice));

//     /* Kernel launch configuration */
//     const int TILE = 16; // block dimension (16x16 threads)
//     dim3 blockDim(TILE, TILE);
//     dim3 gridDim((N + TILE - 1) / TILE, (N + TILE - 1) / TILE);

//     /* Launch kernel */
//     matmul_kernel<<<gridDim, blockDim>>>(d_A, d_B, d_C, N);
//     CHECK_CUDA(cudaGetLastError());          // check kernel launch

//     /* Copy result back to host */
//     CHECK_CUDA(cudaMemcpy(h_C, d_C, bytes, cudaMemcpyDeviceToHost));

//     /* (Optional) Verify result for a few elements */
//     printf("Sample results:\n");
//     for (int i = 0; i < std::min(N, 5); ++i) {
//         for (int j = 0; j < std::min(N, 5); ++j) {
//             printf("%6.1f ", h_C[i * N + j]);
//         }
//         printf("\n");
//     }

//     /* Free device memory */
//     CHECK_CUDA(cudaFree(d_A));
//     CHECK_CUDA(cudaFree(d_B));
//     CHECK_CUDA(cudaFree(d_C));

//     /* Free host memory */
//     free(h_A);
//     free(h_B);
//     free(h_C);

//     printf("Matrix multiplication finished successfully.\n");
//     return 0;
// }

#include <cuda_runtime.h>
#include <iostream>

int main() {
    int deviceCount;
    cudaError_t error = cudaGetDeviceCount(&deviceCount);
    if (error != cudaSuccess) {
        std::cerr << "CUDA error: " << cudaGetErrorString(error) << std::endl;
        return -1;
    }
    std::cout << "Number of CUDA-capable devices: " << deviceCount << std::endl;
    return 0;
}   