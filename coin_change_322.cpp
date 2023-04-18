// 322. Coin Change

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[amount] = least trial
        // dp[0] = 0
        // solution = min(dp[remaining] + 1, dp[i])

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int j = 0; j < coins.size(); j++)
        {
            for (int i = 1; i <= amount; i++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

class Solution
{
    int max_amount = 10001;
    int dfs(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return max_amount;
        if (i >= coins.size())
            return max_amount;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        return dp[i][amount] = min(dfs(i + 1, amount, coins, dp), 1 + dfs(i, amount - coins[i], coins, dp));
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int res = dfs(0, amount, coins, dp);
        return (res == max_amount) ? -1 : res;
    }
};