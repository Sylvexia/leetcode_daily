// 2658. Maximum Number of Fish in a Grid

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int dirs[5] = {1, 0, -1, 0, 1};
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    int cur = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (q.size())
                    {
                        auto [fi, fj] = q.front();
                        q.pop();
                        cur += grid[fi][fj];
                        grid[fi][fj] = 0;

                        for (int d = 0; d < 4; d++)
                        {
                            int ti = fi + dirs[d];
                            int tj = fj + dirs[d + 1];
                            if (ti < 0 or ti >= grid.size() or
                                tj < 0 or tj >= grid[0].size() or
                                grid[ti][tj] == 0)
                                continue;
                            q.push({ti, tj});
                        }
                    }
                    res = max(res, cur);
                }
            }
        }

        return res;
    }
};