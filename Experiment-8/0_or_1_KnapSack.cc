#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Selected items: ");
    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i - 1);
            w -= weights[i - 1];
        }
        i--;
    }
    printf("\n");
    return dp[n][capacity];
}

int main() {
    int n;
    printf("Enter Number of items: ");
    scanf("%d", &n);
    int weights[n], profits[n];
    printf("Enter Weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
    int capacity;
    printf("Enter max capacity: ");
    scanf("%d", &capacity);
    int maxValue = knapsack(weights, profits, n, capacity);
    printf("Maximum value: %d\n", maxValue);
    return 0;
}

/*
Sample Output:
Enter Number of items: 3
Enter Weights: 10 20 30
Enter profits: 60 100 120
Enter max capacity: 50
Selected items: 1 0
Maximum value: 160
*/
