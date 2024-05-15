// 2812. Find the Safest Path in a Grid

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int dir[5] = {1, 0, -1, 0, 1};
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    q.push({i, j});
        }

        while (!q.empty()) {
            auto [fi, fj] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ti = fi + dir[d], tj = fj + dir[d + 1];
                if (ti < 0 or tj < 0 or ti >= n or tj >= n or grid[ti][tj] != 0)
                    continue;

                grid[ti][tj] = grid[fi][fj] + 1;
                q.push({ti, tj});
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        while (true) {
            auto [cost, pi, pj] = pq.top();
            if (pi == n - 1 and pj == n - 1)
                break;
            pq.pop();
            for (int d = 0; d < 4; d++) {
                int ci = pi + dir[d], cj = pj + dir[d + 1];

                if (ci < 0 or cj < 0 or ci >= n or cj >= n or grid[ci][cj] <= 0)
                    continue;

                pq.push({min(grid[ci][cj], cost), ci, cj});
                grid[ci][cj] = -1;
            }
        }
        return get<0>(pq.top()) - 1;
    }
};