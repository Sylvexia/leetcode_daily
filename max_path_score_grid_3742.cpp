// 3742. Maximum Path Score in a Grid

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int c, const int k, const vector<vector<int>> &grid)
    {
        if (i < 0 or j < 0 or c > k)
            return INT_MIN;

        if (dp[i][j][c] != -1)
            return dp[i][j][c];

        int val = grid[i][j];
        int cost = c + (val != 0);

        if (i == 0 && j == 0)
            return val;

        if (cost > k)
            return dp[i][j][c] = INT_MIN;
        return dp[i][j][c] = val + max(dfs(i - 1, j, cost, k, grid),
                                       dfs(i, j - 1, cost, k, grid));
    }

public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int res = dfs(m - 1, n - 1, 0, k, grid);
        return res < 0 ? -1 : res;
    }
};