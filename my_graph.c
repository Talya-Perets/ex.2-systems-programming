#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"



int main() {
    int i, j;
    char choice;

    // Allocate memory
    int **matrix = malloc(MATRIX_SIZE * sizeof(int*));  // Allocate an array of int pointers

    for (i = 0; i < MATRIX_SIZE; ++i)
        matrix[i] = malloc(MATRIX_SIZE * sizeof(int));  // Allocate an array of ints for each row

    do {
        scanf(" %c", &choice);  // Added space before %c to consume any whitespaces

        switch (choice) {
            case 'A':
                initializeMatrix(matrix, MATRIX_SIZE);
                break;

            case 'B':
                scanf("%d%d", &i, &j);
                printf("%s\n", isTherePath(matrix, i, j, MATRIX_SIZE) ? "True" : "False");
                break;

            case 'C':
                scanf("%d%d", &i, &j);
                int shortestPath = findTheShortestPath(matrix, i, j, MATRIX_SIZE); // Ensure the function name matches
                printf("%d\n", shortestPath);
                break;

            default:
                break;
        }
    } while (choice != 'D');

    // Free memory to end program
    for (i = 0; i < MATRIX_SIZE; ++i)
        free(matrix[i]);

    free(matrix);

    return 0;
}