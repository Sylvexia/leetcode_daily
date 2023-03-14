// 309. Best Time to Buy and Sell Stock with Cooldown

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(vector<int> &prices, int i, bool can_buy, vector<vector<int>> &mem)
    {
        if (i >= prices.size())
            return 0;

        if (mem[i][can_buy] != -1)
            return mem[i][can_buy];

        if (can_buy)
        {
            int buy = dfs(prices, i + 1, false, mem) - prices[i];
            int cd = dfs(prices, i + 1, true, mem);
            return mem[i][can_buy] = max(buy, cd);
        }

        int sell = dfs(prices, i + 2, true, mem) + prices[i];
        int cd = dfs(prices, i + 1, false, mem);
        return mem[i][can_buy] = max(sell, cd);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 3, vector<int>(2, -1));
        return dfs(prices, 0, true, dp);
    }
};