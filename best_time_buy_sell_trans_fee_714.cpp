// 714. Best Time to Buy and Sell Stock with Transaction Fee

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(vector<int> &prices,
            int fee,
            int i,
            bool canBuy,
            vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        int res = dfs(prices, fee, i + 1, canBuy, dp);
        if (canBuy)
            res = max(res, dfs(prices, fee, i + 1, false, dp) - prices[i]);
        else
            res = max(res, dfs(prices, fee, i + 1, true, dp) + prices[i] - fee);
        dp[i][canBuy] = res;
        return res;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(prices, fee, 0, true, dp);
    }
};