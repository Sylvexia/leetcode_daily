// 879. Profitable Schemes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[101][101][101];

    int dfs(int n, int p, int i, vector<int> &group, vector<int> &profit)
    {
        if (n < 0)
            return 0;

        if (i >= profit.size())
        {
            if (p > 0)
                return 0;
            return 1;
        }

        if (p < 0)
            p = 0;

        if (dp[n][p][i] != -1)
            return dp[n][p][i];

        int res = 0;

        int pick = dfs(n - group[i], p - profit[i], i + 1, group, profit) % 1000000007;
        int not_pick = dfs(n, p, i + 1, group, profit) % 1000000007;

        res += (pick + not_pick) % 1000000007;

        return dp[n][p][i] = res;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(n, minProfit, 0, group, profit);
    }
};