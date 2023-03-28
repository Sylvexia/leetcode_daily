// 983. Minimum Cost For Tickets

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[366];
    int dfs(vector<int> &costs, bool hasday[366], int i)
    {
        if (i > 365)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        if (!hasday[i])
            return dp[i] = dfs(costs, hasday, i + 1);

        return dp[i] = min(
                   {dfs(costs, hasday, i + 1) + costs[0],
                    dfs(costs, hasday, i + 7) + costs[1],
                    dfs(costs, hasday, i + 30) + costs[2]});
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        bool hasday[366];
        memset(dp, -1, sizeof(dp));
        memset(hasday, false, sizeof(hasday));

        for (auto d : days)
            hasday[d] = true;
        return dfs(costs, hasday, 1);
    }
};