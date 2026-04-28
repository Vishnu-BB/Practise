#include <stdio.h>

__global__ void hellofromgpu (void){
    printf("helle from gpu\n");
}
int main(void){

    printf("hello world from cpu\n");

    hellofromgpu <<<10, 10>>>();
    
    cudaDeviceReset();
    return 0;
}