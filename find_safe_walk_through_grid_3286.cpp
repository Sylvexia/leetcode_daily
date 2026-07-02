// 3286. Find a Safe Walk Through a Grid

#include <climits>
#include <iostream>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size(), n = grid[0].size();
        constexpr int DIR[5] = {0, -1, 0, 1, 0};

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = grid[0][0];

        using tii = tuple<int, int, int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        pq.push({grid[0][0], 0, 0});

        while (pq.size()) {
            auto [curCost, curI, curJ] = pq.top();
            pq.pop();

            if (curI == m - 1 and curJ == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int ti = curI + DIR[i];
                int tj = curJ + DIR[i + 1];

                if (ti < 0 or ti >= m or tj < 0 or tj >= n)
                    continue;

                int newCost = curCost + grid[ti][tj];
                if (newCost >= health)
                    continue;
                if (newCost >= cost[ti][tj])
                    continue;
                cost[ti][tj] = newCost;

                pq.push({newCost, ti, tj});
            }
        }

        return false;
    }
};