#ifndef MY_MAT_H
#define MY_MAT_H

#define MATRIX_SIZE 10 // Adjust this to the size you need
#define INFINITY 1000000 // Define your own 'infinity' value

// Function prototypes for operations on matrices and pathfinding
void initializeMatrix(int** m, int size);
int dijkstra_algorithm(int** m, int start, int dst, int size);
int isTherePath(int** m, int i, int j, int size);
int findTheShortestPath(int** m, int i, int j, int size);

#endif 
