// 64. Minimum Path Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[201][201];
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= grid.size() or j >= grid[0].size())
            return INT_MAX;

        if (i == grid.size() - 1 and j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int a = dfs(grid, i, j + 1);
        int b = dfs(grid, i + 1, j);

        return dp[i][j] = min(a, b) + grid[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0);
    }
};