// 286. Walls and Gates

// lint: 663 · Walls and Gates

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<int, int>> q;
        array<pair<int, int>, 4> dirs = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            auto [ci, cj] = q.front();
            q.pop();

            for (auto &[di, dj] : dirs)
            {
                int ti = ci + di;
                int tj = cj + dj;

                if (ti < 0 or ti >= rooms.size() or
                    tj < 0 or tj >= rooms[0].size() or
                    rooms[ti][tj] != INT_MAX)
                    continue;

                rooms[ti][tj] = rooms[ci][cj] + 1;
                q.push({ti, tj});
            }
        }

        return;
    }
};