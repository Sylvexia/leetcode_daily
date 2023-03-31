// 1444. Number of Ways of Cutting a Pizza

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<vector<int>>> dp;
    vector<vector<int>> pre;
    int m;
    int n;

    int dfs(int k, int r, int c)
    {
        if (pre[r][c] == 0)
            return 0;

        if (k == 0)
            return 1;

        if (dp[r][c][k] != -1)
            return dp[r][c][k];

        int res = 0;

        for (int i = r + 1; i < m; i++)
        {
            if (pre[r][c] - pre[i][c] > 0)
                res = (res + dfs(k - 1, i, c)) % 1000000007;
        }

        for (int j = c + 1; j < n; j++)
        {
            if (pre[r][c] - pre[r][j] > 0)
                res = (res + dfs(k - 1, r, j)) % 1000000007;
        }

        return dp[r][c][k] = res;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        m = pizza.size();
        n = pizza[0].size();
        dp = vector<vector<vector<int>>>(m + 1,
                                         vector<vector<int>>(n + 1,
                                                             vector<int>(k, -1)));

        pre = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                pre[i][j] = (pizza[i][j] == 'A') +
                            pre[i + 1][j] +
                            pre[i][j + 1] -
                            pre[i + 1][j + 1];
            }
        }

        return dfs(k - 1, 0, 0);
    }
};