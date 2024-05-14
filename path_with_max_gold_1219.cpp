// 1219. Path with Maximum Gold

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or
            grid[i][j] == 0)
            return 0;

        int cur = grid[i][j];

        grid[i][j] = 0;

        int ret = cur + max({dfs(i + 1, j, grid), dfs(i - 1, j, grid),
                             dfs(i, j + 1, grid), dfs(i, j - 1, grid)});

        grid[i][j] = cur;

        return ret;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res = max(res, dfs(i, j, grid));
            }
        }

        return res;
    }
};