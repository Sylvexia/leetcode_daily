// 2684. Maximum Number of Moves in a Grid

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[1001][1001];

    int dfs(vector<vector<int>> &grid, int i, int j, int prev)
    {
        if (i < 0 or i >= grid.size() or
            j < 0 or j >= grid[0].size() or prev >= grid[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = 1 + max({dfs(grid, i - 1, j + 1, grid[i][j]),
                                   dfs(grid, i, j + 1, grid[i][j]),
                                   dfs(grid, i + 1, j + 1, grid[i][j])});
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int res = 0;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < grid.size(); i++)
            res = max(res, dfs(grid, i, 0, 0));

        return res - 1;
    }
};