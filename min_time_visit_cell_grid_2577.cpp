// 2577. Minimum Time to Visit a Cell In a Grid

#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    typedef pair<int, int> pii;
    typedef tuple<int, int, int> tii;
    bool isVal(int i, int j, int m, int n)
    {
        return i >= 0 and j >= 0 and i < m and j < n;
    }

public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 and grid[1][0] > 1)
            return -1;
        int m = grid.size(), n = grid[0].size();
        vector<pii> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<tii, vector<tii>, greater<tii>> pq;
        pq.push({grid[0][0], 0, 0});
        while (pq.size()) {
            auto [time, curI, curJ] = pq.top();
            pq.pop();

            if (curI == m - 1 and curJ == n - 1)
                return time;

            if (visited[curI][curJ])
                continue;

            visited[curI][curJ] = true;

            for (auto [dI, dJ] : dirs) {
                int newI = curI + dI;
                int newJ = curJ + dJ;
                if (!isVal(newI, newJ, m, n))
                    continue;
                int waitTime = (grid[newI][newJ] - time) % 2 == 0 ? 1 : 0;
                int newTime = max(grid[newI][newJ] + waitTime, time + 1);
                pq.push({newTime, newI, newJ});
            }
        }
        return -1;
    }
};