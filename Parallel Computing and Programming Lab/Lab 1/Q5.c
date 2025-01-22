#include "mpi.h"
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

int main(int argc, char* argv[]) {
    int rank, size;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if (rank % 2 == 0) {
        // Even ranked processes calculate factorial
        int fact = factorial(rank);
        printf("Process %d (Even) - Factorial: %d\n", rank, fact);
    } else {
        // Odd ranked processes calculate Fibonacci
        int fib = fibonacci(rank);
        printf("Process %d (Odd) - Fibonacci: %d\n", rank, fib);
    }
    
    MPI_Finalize();
    return 0;
}
