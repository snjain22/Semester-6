// Simple Calculator

#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){

    int rank, size;
    
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double a = 5.0;
    double b = 10.0;

    switch(rank){
        case 1:
            printf("Process: %d\nAddition: %.2f+%.2f = %.2f\n", rank, a,b,a+b);
            break;
        case 2:
            printf("Process: %d\nSubtraction: %.2f-%.2f=%.2f\n", rank, a,b,a-b);
            break;
        case 3:
            printf("Process: %d\nMultiplication: %.2f*%.2f=%.2f\n", rank, a,b,a*b);
            break;
        case 4:
            printf("Process: %d\nDivision: %.2f/%.2f=%.2f\n", rank, a,b,a/b);
            break;
    }

    MPI_Finalize();
    return 0;
}