#include <stdio.h>

// Define the number of vertices in the graph
#define NUM_VERTICES 4

// Define a very large value to represent "infinity" (no connection)
#define INFINITY 999

// Function to display the matrix
void printMatrix(int distanceMatrix[NUM_VERTICES][NUM_VERTICES]) {
    for (int row = 0; row < NUM_VERTICES; row++) {
        for (int col = 0; col < NUM_VERTICES; col++) {
            if (distanceMatrix[row][col] == INFINITY)
                printf("%5s", "INF");
            else
                printf("%5d", distanceMatrix[row][col]);
        }
        printf("\n");
    }
}

// Function implementing the Floyd-Warshall algorithm
void floydWarshall(int graph[NUM_VERTICES][NUM_VERTICES]) {
    // Create a distance matrix initialized with input graph
    int distanceMatrix[NUM_VERTICES][NUM_VERTICES];

    // Copy input graph values into the distance matrix
    for (int row = 0; row < NUM_VERTICES; row++) {
        for (int col = 0; col < NUM_VERTICES; col++) {
            distanceMatrix[row][col] = graph[row][col];
        }
    }

    // Iteratively update the shortest distances
    for (int via = 0; via < NUM_VERTICES; via++) { // Intermediate vertex
        for (int start = 0; start < NUM_VERTICES; start++) { // Source vertex
            for (int end = 0; end < NUM_VERTICES; end++) { // Destination vertex
                // Check if a shorter path exists via the "via" vertex
                if (distanceMatrix[start][via] + distanceMatrix[via][end] < distanceMatrix[start][end]) {
                    distanceMatrix[start][end] = distanceMatrix[start][via] + distanceMatrix[via][end];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printf("Shortest distance matrix:\n");
    printMatrix(distanceMatrix);
}

int main() {
    // Input graph represented as an adjacency matrix
    // If there is no direct edge between two vertices, use INFINITY
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 3, INFINITY, 5},
        {2, 0, INFINITY, 4},
        {INFINITY, 1, 0, INFINITY},
        {INFINITY, INFINITY, 2, 0}
    };

    // Call the Floyd-Warshall function
    floydWarshall(graph);

    return 0;
}
