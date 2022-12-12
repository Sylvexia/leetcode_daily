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

class Solution2
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            auto [row, col] = pair{p.first + dir[k].first, p.second + dir[k].second};
                            if (row >= 0 && row < grid.size() &&
                                col >= 0 && col < grid[0].size() &&
                                grid[row][col] == '1')
                            {
                                grid[row][col] = '0';
                                q.push({row, col});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution2 sol;
    vector<vector<char>> data = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << sol.numIslands(data);
}