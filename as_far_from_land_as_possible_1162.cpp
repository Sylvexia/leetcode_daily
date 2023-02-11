// 1162. As Far from Land as Possible

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &grid, int i, int j, int dist)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or
            (grid[i][j] <= dist and grid[i][j] != 0))
            return;
        grid[i][j] = dist;
        dfs(grid, i + 1, j, dist + 1);
        dfs(grid, i - 1, j, dist + 1);
        dfs(grid, i, j + 1, dist + 1);
        dfs(grid, i, j - 1, dist + 1);
    }

public:
    int maxDistance(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    dfs(grid, i, j, 1);
                }
            }
        }

        int ret{-1};

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] > 1)
                    ret = max(ret, grid[i][j]);
            }
        }

        return (ret == -1) ? -1 : ret - 1;
    }
}; // this get tle when the island dist is large

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int res{0};

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                    continue;

                grid[i][j] = 255;

                if (i > 0)
                    grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
                if (j > 0)
                    grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
            }
        }

        for (int i = grid.size() - 1; i >= 0; --i)
        {
            for (int j = grid[0].size() - 1; j >= 0; --j)
            {
                if (grid[i][j] == 1)
                    continue;

                if (i < grid.size() - 1)
                    grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
                if (j < grid[0].size() - 1)
                    grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);

                res = max(res, grid[i][j]);
            }
        }

        return res == 255 ? -1 : res - 1;
    }
};