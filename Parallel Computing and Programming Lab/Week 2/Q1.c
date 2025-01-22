/*
Q1
---
Write a MPI program using synchronous send. The sender process sends a word to the
receiver. The second process receives the word, toggles each letter of the word and sends
it back to the first process. Both processes use synchronous send operations.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mpi.h"

void toggle_case(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (islower(word[i])) {
            word[i] = toupper(word[i]);  // Convert to uppercase
        } else if (isupper(word[i])) {
            word[i] = tolower(word[i]);  // Convert to lowercase
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    char word[100];
    MPI_Status status;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0) {
            printf("This program requires exactly 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        // Sender process
        printf("Enter a word: ");
        scanf("%s", word);  // Read a word from the user

        // Send the word to the receiver process using synchronous send
        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 (Sender) sent the word: %s\n", word);

        // Receive the modified word back from process 1
        MPI_Recv(word, 100, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
        printf("Process 0 (Sender) received the modified word: %s\n", word);

    } else if (rank == 1) {
        // Receiver process

        // Receive the word from process 0
        MPI_Recv(word, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process 1 (Receiver) received the word: %s\n", word);

        // Toggle the case of each letter in the word
        toggle_case(word);

        // Send the modified word back to process 0 using synchronous send
        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        printf("Process 1 (Receiver) sent the modified word: %s\n", word);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
