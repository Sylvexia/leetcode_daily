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

        vector<int> dp(amount + 1, amount+1);
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