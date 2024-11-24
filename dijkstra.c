#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];    // Array to store the shortest distance from the source
    int sptSet[MAX];  // Boolean array to track vertices included in the shortest path tree

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance to the source is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist[] of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // Update the distance if there is an edge from u to v and v is not in sptSet
            if (graph[u][v] != 0 && sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}

int main() {
    int n = 5;  // Number of vertices

    // Input graph (adjacency matrix)
    // 0 means no edge between vertices
    int graph[MAX][MAX] = {
        {0, 10, 0, 0, 0},
        {10, 0, 5, 0, 0},
        {0, 5, 0, 20, 1},
        {0, 0, 20, 0, 2},
        {0, 0, 1, 2, 0}
    };

    int src = 0; // Starting vertex (source)

    // Call Dijkstra's algorithm
    dijkstra(graph, n, src);

    return 0;
}
//The shortest distance from vertex 0 to vertex 2 is 15, and so on.
