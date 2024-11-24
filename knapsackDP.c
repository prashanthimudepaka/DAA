#include<stdio.h>

// Function to get the maximum of two values
int max(int a, int b) { 
    return (a > b) ? a : b; 
}

// Function to solve the Knapsack problem using dynamic programming
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];  // 2D array to store solutions for subproblems

    // Build the table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;  // No items or zero capacity, value is zero
            } else if (wt[i-1] <= w) {
                // Include the item if it fits in the current capacity
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            } else {
                // Do not include the item
                K[i][w] = K[i-1][w];
            }
        }
    }

    // The maximum value is stored in K[n][W]
    return K[n][W];
}

int main() {
    int i, n = 3, val[20] = {60, 100, 120}, wt[20] = {10, 20, 30}, W = 50;  // Static inputs
    
    // Call the knapSack function and print the result
    printf("Maximum profit: %d\n", knapSack(W, wt, val, n));
    
    return 0;
}
