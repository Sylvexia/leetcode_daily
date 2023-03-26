// 2596. Check Knight Tour Configuration

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int total = grid.size() * grid[0].size() - 1;
        int avail = true;
        int count = 0;
        int i = 0, j = 0;
        vector<pair<int, int>> dirs{{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

        while (avail)
        {
            if (count == total)
                return true;

            avail = false;
            for (const auto &[di, dj] : dirs)
            {
                int ti = i + di;
                int tj = j + dj;

                if (ti < 0 or ti >= grid.size() or
                    tj < 0 or tj >= grid[0].size() or
                    grid[ti][tj] != (count + 1))
                {
                    continue;
                }
                if (grid[ti][tj] == (count + 1))
                {
                    i = ti;
                    j = tj;
                    avail = true;
                    break;
                }
            }
            count++;
        }

        return false;
    }
};