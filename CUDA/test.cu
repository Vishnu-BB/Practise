// #include <iostream>
// #include <cuda_runtime.h>

// int main() {
//     int deviceCount = 0;
//     // Get the number of CUDA-capable devices
//     cudaError_t error = cudaGetDeviceCount(&deviceCount);

//     if (error != cudaSuccess) {
//         std::cerr << "CUDA Error: " << cudaGetErrorString(error) << std::endl;
//         return 1;
//     }

//     if (deviceCount == 0) {
//         std::cout << "No CUDA devices found." << std::endl;
//     } else {
//         std::cout << "Found " << deviceCount << " CUDA device(s):" << std::endl;
//     }

//     for (int i = 0; i < deviceCount; ++i) {
//         cudaDeviceProp prop;
//         // Retrieve properties for device 'i'
//         cudaGetDeviceProperties(&prop, i);

//         std::cout << "\nDevice " << i << ": " << prop.name << std::endl;
//         std::cout << "  Compute Capability:          " << prop.major << "." << prop.minor << std::endl;
//         std::cout << "  Total Global Memory:         " << prop.totalGlobalMem / (1024 * 1024) << " MB" << std::endl;
//         std::cout << "  Shared Memory per Block:     " << prop.sharedMemPerBlock / 1024 << " KB" << std::endl;
//         std::cout << "  Registers per Block:         " << prop.regsPerBlock << std::endl;
//         std::cout << "  Warp Size:                   " << prop.warpSize << std::endl;
//         std::cout << "  Max Threads per Block:       " << prop.maxThreadsPerBlock << std::endl;
//         std::cout << "  Multi-processor Count:       " << prop.multiProcessorCount << std::endl;
//         // std::cout << "  Clock Rate:                  " << prop.clockRate / 1000 << " MHz" << std::endl;
//     }

//     return 0;
// }

// _____________________________________________________________________________________

#include <iostream>
#include <cuda_runtime.h>

int main() {
    int deviceCount = 0;
    cudaGetDeviceCount(&deviceCount);

    if (deviceCount == 0) {
        std::cout << "No CUDA-capable devices found." << std::endl;
        return 0;
    }

    for (int i = 0; i < deviceCount; ++i) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);

        // Hardware threads = (Number of SMs) * (Max threads per SM)
        int totalHardwareThreads = prop.multiProcessorCount * prop.maxThreadsPerMultiProcessor;

        std::cout << "Device " << i << ": " << prop.name << std::endl;
        std::cout << "  Multiprocessors (SMs):       " << prop.multiProcessorCount << std::endl;
        std::cout << "  Max Threads per SM:          " << prop.maxThreadsPerMultiProcessor << std::endl;
        std::cout << "  -------------------------------------------------" << std::endl;
        std::cout << "  Total Hardware Thread Count: " << totalHardwareThreads << std::endl;
        std::cout << "  -------------------------------------------------" << std::endl;
    }

    return 0;
}
