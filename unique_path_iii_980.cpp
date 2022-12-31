// 980. Unique Paths III

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int m_res = 0, m_empty = 1; // include the end
    void dfs(vector<vector<int>> &grid, int i, int j, int count)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2)
        {
            if (m_empty == count)
                m_res++;
            return;
        }

        grid[i][j] = -1;
        dfs(grid, i + 1, j, count + 1);
        dfs(grid, i - 1, j, count + 1);
        dfs(grid, i, j + 1, count + 1);
        dfs(grid, i, j - 1, count + 1);
        grid[i][j] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int start_i = -1, start_j = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    start_i = i, start_j = j;
                else if (grid[i][j] == 0)
                    m_empty++;
            }
        }

        dfs(grid, start_i, start_j, 0);

        return m_res;
    }
};