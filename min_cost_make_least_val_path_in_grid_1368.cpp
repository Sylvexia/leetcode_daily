// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i,
             int j,
             int curCost,
             vector<vector<int>> &cost,
             vector<vector<int>> &grid,
             queue<pair<int, int>> &queue)
    {
        int m = cost.size();
        int n = cost[0].size();
        if (i < 0 or i >= m or j < 0 or j >= n or cost[i][j] != INT_MAX)
            return;
        cost[i][j] = curCost;
        queue.push({i, j});
        int nextDir = grid[i][j] - 1;
        dfs(i + dir[nextDir][0], j + dir[nextDir][1], curCost, cost, grid,
            queue);
        return;
    }

public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int curCost = 0;

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dfs(0, 0, curCost, cost, grid, q);
        while (q.size()) {
            curCost++;
            int qsize = q.size();
            for (int c = 0; c < qsize; c++) {
                auto [new_i, new_j] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++)
                    dfs(new_i + dir[d][0], new_j + dir[d][1], curCost, cost,
                        grid, q);
            }
        }
        return cost[m - 1][n - 1];
    }
};