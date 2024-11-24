#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int ary[MAX][MAX];  // Cost matrix
int dp[1025][MAX];  // DP table: 2^n * n
int visited[1025];  // To check if the state has been computed

// Function to find the minimum cost using dynamic programming
int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) {
        return ary[pos][0];  // Return to the starting point
    }

    if(visited[mask] & (1 << pos)) {
        return dp[mask][pos];
    }

    int minCost = INT_MAX;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {  // If city has not been visited
            int newCost = ary[pos][city] + tsp(mask | (1 << city), city);
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    dp[mask][pos] = minCost;  // Store the result
    visited[mask] |= (1 << pos);  // Mark this state as visited
    return minCost;
}

void takeInput() {
    int i, j;
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    printf("\nEnter the Cost Matrix\n");
    for(i = 0; i < n; i++) {
        printf("\nEnter Elements of Row: %d\n", i + 1);
        for(j = 0; j < n; j++) {
            scanf("%d", &ary[i][j]);
        }
    }
}

int main() {
    takeInput();

    // Initialize the DP table with -1 (indicating that state hasn't been computed yet)
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from the first village (index 0) with only the first village visited (mask = 1)
    int result = tsp(1, 0);
    printf("\nThe minimum cost is %d\n", result);
    return 0;
}
