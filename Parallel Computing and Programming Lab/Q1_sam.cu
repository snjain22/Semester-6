// Q1. Write program in CUDA to add 2 vectors of length N using 
// A) Block Size as N
// B) N Threads

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void add(int *a, int *b, int *c, int n) {
    // Perform the addition
    int globalIdx = blockIdx.x * blockDim.x + threadIdx.x;

    if(globalIdx < n){
        c[globalIdx] = a[globalIdx] + b[globalIdx];
    }
}

int main(void) {
    int n; // size of array
    int *h_a, *h_b, *h_c, *d_a, *d_b, *d_c; // device copies of variables a, b & c
    
    n=12;

    int size = n * sizeof(int);

    // HOST Memory allocated
    h_a = (int*)malloc(size);
    h_b = (int*)malloc(size);
    h_c = (int*)malloc(size);

    // Allocate space for device copies of h_a, h_b, h_c
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);

    // Initializing the Array's
    for(int i=0 ; i<size; i++){
        h_a[i] = i;
        h_b[i] = 5*i;
    }

    // Copy inputs to device
    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, h_c, size, cudaMemcpyHostToDevice);


    // Launch add() kernel on GPU
    add<<< 1, n >>>(d_a, d_b, d_c, n);

    // Copy result back to host
    cudaMemcpy(&h_c, d_c, size, cudaMemcpyDeviceToHost);

    // Print the result
    printf("Array: ");
    for(int i = 0 ; i<n ; i++){
        printf("%d ", h_c[i]);
    }

    // Cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
