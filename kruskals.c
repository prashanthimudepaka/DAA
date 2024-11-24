#include <stdio.h>

#define MAX 10

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the root of a node (for union-find)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    // Union by rank
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(struct Edge edges[], int V, int E) {
    int parent[V], rank[V];
    struct Edge result[V-1]; // Array to store the MST
    int e = 0;  // Count of edges in MST

    // Initialize parent and rank for Union-Find
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by increasing weight (simple bubble sort for simplicity)
    for (int i = 0; i < E-1; i++) {
        for (int j = i+1; j < E; j++) {
            if (edges[i].weight > edges[j].weight) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Process each edge and add it to the MST if it doesn't form a cycle
    for (int i = 0; i < E; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            result[e++] = edges[i];
            unionSets(parent, rank, x, y);
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    int mst_cost = 0;
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        mst_cost += result[i].weight;
    }

    printf("\nMinimum Cost of Spanning Tree: %d\n", mst_cost);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    // Array of edges (src, dest, weight)
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 8},
        {0, 3, 9},
        {1, 5, 15},
        {2, 3, 4}
    };

    // Call Kruskal's algorithm to find MST
    kruskal(edges, V, E);

    return 0;
}
