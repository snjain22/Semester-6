#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int value;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Ensure there are at least 2 processes
    if (size < 2) {
        if (rank == 0) {
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    // Root process (rank 0) reads the initial value
    if (rank == 0) {
        printf("Enter an integer value: ");
        scanf("%d", &value);

        // Send the value to process 1 (rank 1)
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Root process sent value %d to process 1.\n", value);
    } else {
        // Intermediate processes (rank 1 to rank N-2) receive and send the incremented value
        MPI_Recv(&value, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        value++;  // Increment the received value
        printf("Process %d received value %d, incremented it to %d, and sending to process %d.\n", rank, value - 1, value, rank + 1);

        // Send the incremented value to the next process
        if (rank < size - 1) {
            MPI_Send(&value, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }
    }

    // Last process (rank N-1) sends the incremented value back to root
    if (rank == size - 1) {
        MPI_Recv(&value, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        value++;  // Increment the value one more time
        printf("Process %d received value %d, incremented it to %d, and sending it back to root.\n", rank, value - 1, value);

        // Send the incremented value back to the root process (rank 0)
        MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    // Root process receives the final value and prints it
    if (rank == 0) {
        MPI_Recv(&value, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Root process received the final value %d from process %d.\n", value, size - 1);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
