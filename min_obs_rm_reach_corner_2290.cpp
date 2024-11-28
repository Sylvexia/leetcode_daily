// 2290. Minimum Obstacle Removal to Reach Corner

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool isVal(vector<vector<int>> &grid, int i, int j)
    {
        return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
    }

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        minCost[0][0] = grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({minCost[0][0], 0, 0});
        while (!pq.empty()) {
            auto [curCost, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 and j == n - 1)
                return curCost;

            for (auto [di, dj] : dirs) {
                int new_i = i + di;
                int new_j = j + dj;
                if (isVal(grid, new_i, new_j)) {
                    int newCost = curCost + grid[i][j];
                    if (newCost < minCost[new_i][new_j]) {
                        minCost[new_i][new_j] = newCost;
                        pq.push({newCost, new_i, new_j});
                    }
                }
            }
        }
        return minCost[m - 1][n - 1];
    }
};