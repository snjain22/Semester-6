// // MPI Program to find out pow(x,rank) for all processes 
// // where 'x' is the integer constant and 'rank' is 
// // the rank of the process.

#include "mpi.h"
#include<stdio.h>
// // #include<math.h>

double power(int base, int exponent){
    double result = 1.0;

    for(int i = 0 ; i<exponent; i++){
        result *= base;
    }

    return result;
}

int main(int argc, char* argv[]){
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Process: %d, Pow(2,%d): %.0f\n", rank, rank, power(2 , rank));

    MPI_Finalize();

    return 0;
}

// #include "mpi.h"
// #include <stdio.h>

// double power(double base, int exponent) {
//     double result = 1.0;
//     for(int i = 0; i < exponent; i++) {
//         result *= base;
//     }
//     return result;
// }

// int main(int argc, char* argv[]) {
//     int rank, size;
    
//     MPI_Init(&argc, &argv);
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     MPI_Comm_size(MPI_COMM_WORLD, &size);
    
//     double result = power(2.0, rank);
//     printf("Process: %d, Pow(2,%d): %.0f\n", rank, rank, result);
    
//     MPI_Finalize();
//     return 0;
// }
