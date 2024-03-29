// 518. Coin Change II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(int n, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 0;
        if (amount == 0)
            return 1;

        if (dp[n][amount] != -1)
            return dp[n][amount];

        if (coins[n - 1] > amount)
        {
            dp[n][amount] = dfs(n - 1, amount, coins, dp);
            return dp[n][amount];
        }

        dp[n][amount] = dfs(n, amount - coins[n - 1], coins, dp) + dfs(n - 1, amount, coins, dp);
        return dp[n][amount];
    }

public:
    int change(int amount, vector<int> &coins)
    {
        // amount == ia+jb+kc+...
        // amount[5] == amount[3] + 2;
        // amount[3]==amount[2]+1
        int n = coins.size();
        if (amount == 0)
            return 1;
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return dfs(n, amount, coins, dp);
    }
};

// redo
class Solution
{
    int dfs(int amount, vector<int> &coins, int i, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;

        if (i == coins.size() or amount < 0)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        return dp[i][amount] = dfs(amount - coins[i], coins, i, dp) + dfs(amount, coins, i + 1, dp);
    }

public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(amount, coins, 0, dp);
    }
};