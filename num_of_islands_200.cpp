// 200. Number of Islands

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), result{};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    erase_grid(grid, i, j);
                }
            }
        }
        return result;
    }

    void erase_grid(vector<vector<char>> &grid, int i, int j)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;

        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        erase_grid(grid, i + 1, j);
        erase_grid(grid, i, j + 1);
        erase_grid(grid, i - 1, j);
        erase_grid(grid, i, j - 1);
        return;
    }
};