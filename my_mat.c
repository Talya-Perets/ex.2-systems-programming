#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>

#define INFINITY 1000000 

//This function initializes your matrix by reading values from the user input.
void initializeMatrix(int** m, int size) {
for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; j++)
        {
          scanf("%d", &m[i][j]);        }
        
    }
}

int dijkstra_algorithm(int** m, int start, int dst, const int size) {
    int distanceFromStart[size], count = 0, min, u;
    bool scannedVert[size];

    for (int i = 0; i < size; i++) {
        // Set the initial distance to all vertices as INFINITY
        distanceFromStart[i] = INFINITY;
        // Mark all vertices as unvisited
        scannedVert[i] = false;
    }

    // The distance from start to itself is 0
    distanceFromStart[start] = 0;

    while (++count < size) {
        min = INFINITY;

        for (int v = 0; v < size; ++v) {
            if (!scannedVert[v] && distanceFromStart[v] < min) {
                min = distanceFromStart[v];
                u = v;
            }
        }

        scannedVert[u] = true;

        for (int v = 0; v < size; v++) {
            // If 'v' is unvisited and there is an edge from 'u' to 'v'
            // and the distance to 'u' is not INFINITY (i.e., 'u' is reachable)
            // and the path from 'start' to 'v' via 'u' is shorter than the current known path to 'v'
            if (!scannedVert[v] && m[u][v] && distanceFromStart[u] != INFINITY &&
                distanceFromStart[u] + m[u][v] < distanceFromStart[v]) {
                distanceFromStart[v] = distanceFromStart[u] + m[u][v];  // Update distance
            }
        }
    }

    return distanceFromStart[dst];
}


int isTherePath(int** m, int i, int j, int size) {
    // Directly check if there's an edge between i and j
    if (m[i][j]) {
        return true;
    }

    // Call dijkstra_algorithm to find the shortest distance from i to j
    int shortestDistance = dijkstra_algorithm(m, i, j, size);
    
    // Return true if the shortest distance is less than INFINITY and not 0
    return (shortestDistance < INFINITY && shortestDistance != 0);
}


int findTheShortestPath(int** m, int i, int j, int size) {
    
    int shortestDistance = dijkstra_algorithm(m, i, j, size);
    return ((shortestDistance && shortestDistance != INFINITY) ? shortestDistance : -1);
}
