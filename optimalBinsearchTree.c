#include <stdio.h>
#include <limits.h>

// Function to find the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k]; // Sum all the frequencies in the range
    }
    return s;
}

// Function to calculate the optimal cost of the BST
int optimalSearchTree(int keys[], int freq[], int n) {
    // Create a table to store the minimum cost of BSTs
    int dp[n][n];

    // Base case: The cost of one key is simply its frequency
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    // Fill the DP table
    for (int length = 2; length <= n; length++) { // length of the subarray
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1; // j is the end index of the subarray
            dp[i][j] = INT_MAX; // Set initial value to a large number

            // Try all possible roots and calculate the cost
            for (int r = i; r <= j; r++) {
                // Calculate the cost of the current root 'r'
                int cost = (r > i ? dp[i][r-1] : 0) + 
                           (r < j ? dp[r+1][j] : 0) + sum(freq, i, j);

                // Update the minimum cost for the subarray (i, j)
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result for the full array (0 to n-1) will be in dp[0][n-1]
    return dp[0][n-1];
}

int main() {
    // Static input
    int keys[] = {10, 20, 30, 40};  // Keys in the BST
    int freq[] = {4, 2, 6, 3};  // Frequencies for each key
    int n = sizeof(keys) / sizeof(keys[0]);  // Number of keys

    // Call the function and print the result
    printf("Cost of Optimal BST is %d\n", optimalSearchTree(keys, freq, n));
    
    return 0;
}
