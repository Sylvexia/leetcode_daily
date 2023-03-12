// 994. Rotting Oranges

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int to_rot;
        bool has_rot;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    has_rot = true;
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    to_rot++;
            }
        }

        if (to_rot == 0)
            return 0;

        if (not has_rot)
            return -1;

        array<pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

        int res = -1;
        while (not q.empty())
        {
            int q_size = q.size();

            for (int c = 0; c < q_size; c++)
            {
                auto [i, j] = q.front();
                q.pop();

                for (auto [di, dj] : dirs)
                {
                    auto [ti, tj] = make_pair(di + i, dj + j);

                    if (ti >= 0 and tj >= 0 and
                        ti < grid.size() and tj < grid[0].size() and
                        grid[ti][tj] == 1)
                    {
                        q.push({ti, tj});
                        grid[ti][tj] = 2;
                        to_rot--;
                    }
                }
            }

            res++;
        }

        if (to_rot != 0)
            return -1;

        return res;
    }
};