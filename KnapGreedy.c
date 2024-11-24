#include <stdio.h>

// Function to solve the Fractional Knapsack Problem
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], totalProfit = 0.0;
    int i;
    float remainingCapacity = capacity;

    // Initialize the result array with 0 (no item taken initially)
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    // Fill the knapsack
    for (i = 0; i < n; i++)
    {
        if (weight[i] > remainingCapacity)
        {
            break; // If the item can't fit, break the loop
        }
        else
        {
            x[i] = 1.0; // Take the whole item
            totalProfit += profit[i];
            remainingCapacity = remainingCapacity - weight[i];
        }
    }

    // If there's still capacity, take a fraction of the next item
    if (i < n)
    {
        x[i] = remainingCapacity / weight[i]; // Fraction of the item
        totalProfit += x[i] * profit[i];      // Add fractional profit
    }

    // Output the results
    printf("\nThe result vector (fractions of items taken) is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }

    printf("\nMaximum profit is: %f\n", totalProfit);
}

// Function to sort items by profit-to-weight ratio in descending order
void sortItems(int n, float weight[], float profit[], float ratio[])
{
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            { // Sort in descending order
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
}

// Main function
int main()
{
    // Static inputs
    int n = 7;                                 // Number of items
    float weight[] = {2, 3, 5, 7, 1, 4, 1};    // Weights of items
    float profit[] = {10, 5, 15, 7, 6, 18, 3}; // Profits of items
    float capacity = 15;                       // Knapsack capacity
    float ratio[20];

    // Calculate profit-to-weight ratio for each item
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items by profit-to-weight ratio
    sortItems(n, weight, profit, ratio);

    // Solve the knapsack problem
    knapsack(n, weight, profit, capacity);

    return 0;
}
