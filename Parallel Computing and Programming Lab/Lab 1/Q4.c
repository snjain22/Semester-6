// String Toggler

#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){

    int rank, size;
    char s[5]= "HellO";
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (s[rank] >= 97){
        s[rank] -=32;
    }

    else{
        s[rank] += 32;
    }

    printf("Process: %d - String: %s\n",rank, s);

    MPI_Finalize();
    return 0;
}