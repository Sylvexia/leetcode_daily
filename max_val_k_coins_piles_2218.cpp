// 2218. Maximum Value of K Coins From Piles

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(const int i, const int k,
            vector<vector<int>> &piles,
            vector<vector<int>> &dp)
    {
        if (i >= piles.size())
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int max_v = dfs(i + 1, k, piles, dp);

        int sum = 0;
        for (int j = 0; j < piles[i].size(); j++)
        {
            if ((k - j - 1) < 0)
                break;

            sum += piles[i][j];
            max_v = max(max_v,
                        (sum + dfs(i + 1, k - 1 - j, piles, dp)));
        }
        return dp[i][k] = max_v;
    }

public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, -1));
        return dfs(0, k, piles, dp);
    }
};