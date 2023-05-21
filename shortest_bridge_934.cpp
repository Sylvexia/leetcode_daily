// 934. Shortest Bridge

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dir[5] = {0, 1, 0, -1, 0};
    void dfs(int i, int j, queue<pair<int, int>> &q, vector<vector<int>> &grid)
    {
        if (min(i, j) < 0 or max(i, j) >= grid.size() or
            grid[i][j] != 1)
            return;

        grid[i][j] = -1;
        q.push({i, j});
        for (int d = 0; d < 4; d++)
            dfs(i + dir[d], j + dir[d + 1], q, grid);
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        bool flag = true;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, q, grid);
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        int res = 0;
        while (q.size())
        {
            int size = q.size();
            res++;

            for (int g = 0; g < size; g++)
            {
                auto [fi, fj] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ti = fi + dir[d];
                    int tj = fj + dir[d + 1];
                    if (min(ti, tj) < 0 or max(ti, tj) >= grid.size())
                        continue;
                    if (grid[ti][tj] == 1)
                        return res - 1;
                    else if (grid[ti][tj] == 0)
                    {
                        q.push({ti, tj});
                        grid[ti][tj] = -1;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << sol.shortestBridge(grid);
}