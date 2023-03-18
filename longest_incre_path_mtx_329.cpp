// 329. Longest Increasing Path in a Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[201][201];
    int dfs(int i, int j, vector<vector<int>> &matrix, int prev)
    {
        if (i < 0 or i >= matrix.size() or
            j < 0 or j >= matrix[0].size() or
            matrix[i][j] <= prev)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = 1 + max({dfs(i + 1, j, matrix, matrix[i][j]),
                                   dfs(i - 1, j, matrix, matrix[i][j]),
                                   dfs(i, j + 1, matrix, matrix[i][j]),
                                   dfs(i, j - 1, matrix, matrix[i][j])});
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        memset(dp, -1, sizeof(dp));

        int res = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                res = max(res, dfs(i, j, matrix, -1));
        }

        return res;
    }
};