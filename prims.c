#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX]; // Array to store constructed MST
    int key[MAX];    // Key values used to pick minimum weight edge
    int mstSet[MAX]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Include the first vertex in the MST
    key[0] = 0; // Start with vertex 0
    parent[0] = -1; // First node is always the root of MST

    // Find the MST for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet, n);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update the key and parent values for adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    // Input the graph (adjacency matrix)
    printf("Enter the adjacency matrix (0 for no edge, other values for weights):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call Prim's algorithm to find MST
    primMST(graph, n);

    return 0;
}
/*Enter the number of vertices: 5
Enter the adjacency matrix (0 for no edge, other values for weights):
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0*/ 
