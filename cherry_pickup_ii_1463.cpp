// 1463. Cherry Pickup II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[71][71][71];
    int m;
    int n;
    int dfs(int r, int c1, int c2, vector<vector<int>> &grid)
    {
        if (r == m)
            return 0;
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int res = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int tc1 = c1 + i, tc2 = c2 + j;
                if (tc1 >= 0 and tc1 < n and tc2 >= 0 and tc2 < n)
                    res = max(res, dfs(r + 1, tc1, tc2, grid));
            }
        }
        int cur = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        dp[r][c1][c2] = res + cur;
        return dp[r][c1][c2];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        m = grid.size();
        n = grid[0].size();
        return dfs(0, 0, n - 1, grid);
    }
};