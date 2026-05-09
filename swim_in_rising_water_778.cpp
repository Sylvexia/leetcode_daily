// 778. Swim in Rising Water

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
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        using iii = tuple<int, int, int>;
        priority_queue<iii, vector<iii>, greater<iii>> minHeap;
        minHeap.push({grid[0][0], 0, 0});

        int dir[5] = {1, 0, -1, 0, 1};

        while (minHeap.size()) {
            auto [h, r, c] = minHeap.top();
            minHeap.pop();

            if (r == n - 1 and c == n - 1)
                return h;
            
            if (visited[r][c])
                continue;

            visited[r][c] = true;


            for (int i = 0; i < 4; i++) {
                int ti = r + dir[i];
                int tj = c + dir[i + 1];
                if (ti < 0 or ti >= n or tj < 0 or tj >= n)
                    continue;
                int cost = max(h, grid[ti][tj]);
                minHeap.push({cost, ti, tj});
            }
        }
        return -1;
    }
};