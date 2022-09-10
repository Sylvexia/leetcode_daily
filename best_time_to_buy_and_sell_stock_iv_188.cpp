// 188. Best Time to Buy and Sell Stock IV

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dp[1000][101][2]{}; // p,k,buy

    int dfs(vector<int> &prices, int p, int k, bool buy)
    {
        if (p >= prices.size() || (k == 0 && buy))
            return 0;

        if (dp[p][k][buy] == 0)
        {
            dp[p][k][buy] = max(dfs(prices, p + 1, k, buy),
                                (buy ? -1 : 1) * prices[p] + dfs(prices, p + 1, k - buy, !buy));
        }
        return dp[p][k][buy];
    }

    int maxProfit2(vector<int> &prices)
    {
        int res{};
        for (int i = 1; i < prices.size(); ++i)
        {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        if (k * 2 >= prices.size())
            return maxProfit2(prices);

        return dfs(prices, 0, k, true);
    }
};