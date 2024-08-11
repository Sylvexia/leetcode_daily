// 1568. Minimum Number of Days to Disconnect Island

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        if (i - 1 >= 0)
            dfs(i - 1, j, grid);
        if (j - 1 >= 0)
            dfs(i, j - 1, grid);
        if (i + 1 < grid.size())
            dfs(i + 1, j, grid);
        if (j + 1 < grid[0].size())
            dfs(i, j + 1, grid);
    }

    int num_island(vector<vector<int>> grid)  // copy
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    res++;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        if (num_island(grid) != 1)
            return 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (num_island(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};