#include <stdio.h>   // for printf
#include <stdlib.h>  // for malloc, free
#include <limits.h>  // for INT_MAX


// Function prototype
int coinChange(int* coins, int coinsSize, int amount);

int main() {
    // 1) Define some coins
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);

    // 2) Define the amount we want to make
    int amount = 11;

    // 3) Call the coinChange function
    int result = coinChange(coins, coinsSize, amount);

    // 4) Print the result
    printf("Coins: ");
    for (int i = 0; i < coinsSize; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    if (result == -1) {
        printf("It is impossible to make amount %d with the given coins.\n", amount);
    } else {
        printf("Minimum number of coins to make amount %d is: %d\n", amount, result);
    }

    return 0;
}

int coinChange(int* coins, int coinsSize, int amount) {
    // If amount is 0, we need 0 coins
    if (amount == 0) {
        return 0;
    }

    // dp_amount_min_coins[x] = minimum number of coins to make amount x
    int* dp_amount_min_coins = (int*)malloc((amount + 1) * sizeof(int));

    // Use a big number with meaning of infinity
    int INF = INT_MAX / 2;  // divide by 2 to avoid overflow

    // Initialize all amounts as "infinity" at first
    for (int i = 0; i <= amount; i++) {
        dp_amount_min_coins[i] = INF;
    }

    // To make amount 0, we need 0 coins
    dp_amount_min_coins[0] = 0;

    // Build the answer from 1 up to amount
    for (int target_amount = 1; target_amount <= amount; target_amount++) {
        // Try each coin
        for (int i = 0; i < coinsSize; i++) {
            int current_coin = coins[i];

            // We can only use this coin if it is not bigger than target_amount
            if (current_coin <= target_amount) {
                int remaining_amount = target_amount - current_coin;

                // If remaining_amount is possible (not INF), we can try using this coin
                if (dp_amount_min_coins[remaining_amount] != INF) {
                    int proposed_min_coins = dp_amount_min_coins[remaining_amount] + 1;

                    // Take the smaller number of coins, if we find smaller combination remember it
                    if (proposed_min_coins < dp_amount_min_coins[target_amount]) {
                        dp_amount_min_coins[target_amount] = proposed_min_coins;
                    }
                }
            }
        }
    }

    int result;
    if (dp_amount_min_coins[amount] == INF) {
        // Still infinity so return -1, what mean not possible
        result = -1;
    } else {
        // We found the minimum number of coins
        result = dp_amount_min_coins[amount];
    }

    free(dp_amount_min_coins); // free the memory
    return result;
}
