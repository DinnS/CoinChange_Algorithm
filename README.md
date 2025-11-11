## Problem description
- We are given an array coins[] with different coin values like {1, 2, 5} and desired amount value like 11

- We want to find minimum number of coins needed to make exactly amount

- If it is impossible to make amount using these coins, we should return -1

- We can use each coin as many times as we can


## Approach explanation

We use dynamic programming tabulation (bottom-up) approach

Idea:

1) Create an array `dp_amount_min_coins[0..amount]`
`dp_amount_min_coins[x]` = minimum number of coins needed to make amount x. So indexes of that array means amount.

2) Set everything to a big number (INF) at the start, meaning “impossible for now”

3) Set `dp_amount_min_coins[0] = 0`, because we need 0 coins to make amount 0

4) Create a loop for checking every amount combination starting from 1 until amount what we are looking for. target_amount is our current search amount.

5) Create a loop for checking every coins 

6) If current coin <= target_amount, then we find remaining_amount by `target_amount - current_coin`

7) If we already know how to make remaining_amout (not INF), then we can make proposed_min_coins using already known combination what needed for remaining_amount and adding one more coin to it (old coins + this one)

8) We should check if new proposed_min_coins is smallest than already known combination number, `proposed_min_coins < dp_amount_min_coins[target_amount]`

9) Finally, we return our result. If desired amount is still INF then we `return -1`, what mean combination is not possible. Otherwise we return combination number `return dp_amount_min_coints[amount]`


## Time and space complexity

n = desired amount
k = number of coins

### Time complexity:

1) We have a loop over all amounts 1..n
2) Inside, we loop over all k coins

So: Time Complexity = O(n * k)

### Space complexity:

1) We have one array of size n + 1 (dp_amount_min_coins)

So: Space Complexity = O(n)
