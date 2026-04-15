#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int res = dp[i - coins[j]] + 1;
                if (res < dp[i])
                    dp[i] = res;
            }
        }
    }

    return dp[amount];
}

// Helper to print coins
void printCoins(int coins[], int n) {
    printf("Coins: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

// Run a single test case
void runTest(int coins[], int n, int amount) {
    printCoins(coins, n);
    printf("Amount: %d\n", amount);

    int result = minCoins(coins, n, amount);

    if (result == INT_MAX)
        printf("Output: No solution\n");
    else
        printf("Output: Minimum coins = %d\n", result);

    printf("-----------------------------\n");
}

int main() {

    printf("=== Coin Change Test Cases ===\n\n");

    // Test Case 1
    int coins1[] = {1, 2, 5};
    runTest(coins1, 3, 11);

    // Test Case 2 (No solution)
    int coins2[] = {2};
    runTest(coins2, 1, 3);

    // Test Case 3 (Greedy fails)
    int coins3[] = {1, 3, 4};
    runTest(coins3, 3, 6);

    // Test Case 4 (Single coin)
    int coins4[] = {5};
    runTest(coins4, 1, 20);

    // Test Case 5 (Edge case)
    int coins5[] = {1, 2, 5};
    runTest(coins5, 3, 0);

    // Test Case 6 (Larger input)
    int coins6[] = {1, 2, 5, 10};
    runTest(coins6, 4, 100);

    return 0;
}