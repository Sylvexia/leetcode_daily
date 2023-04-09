// 1020. Number of Enclaves

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or j < 0 or
            i == grid.size() or j == grid[0].size() or
            grid[i][j] != 1)
            return;

        grid[i][j] = 0;

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            dfs(i, 0, grid);
            dfs(i, grid[0].size() - 1, grid);
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            dfs(0, j, grid);
            dfs(grid.size() - 1, j, grid);
        }

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    res++;
            }
        }

        return res;
    }
};