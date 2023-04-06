// 1254. Number of Closed Islands

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    enum state
    {
        LAND = 0,
        WATER = 1,
        ELIM = 2
    };

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    inline void mark_elim(int i, int j, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        if (grid[i][j] != LAND)
            return;

        q.push({i, j});

        while (q.size())
        {
            auto [fi, fj] = q.front();
            q.pop();
            grid[fi][fj] = ELIM;

            for (auto [di, dj] : dir)
            {
                int ti = di + fi;
                int tj = dj + fj;
                if (ti >= grid.size() or ti < 0 or
                    tj >= grid[0].size() or tj < 0 or
                    grid[ti][tj] != LAND)
                    continue;

                q.push({ti, tj});
            }
        }

        return;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            mark_elim(i, 0, grid);
            mark_elim(i, grid[0].size() - 1, grid);
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            mark_elim(0, j, grid);
            mark_elim(grid.size() - 1, j, grid);
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == LAND)
                {
                    mark_elim(i, j, grid);
                    cout << i << j;
                    res++;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 1, 0},
                                {1, 0, 1, 0, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << sol.closedIsland(grid);
}