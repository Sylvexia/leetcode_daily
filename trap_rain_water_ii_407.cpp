// 407. Trapping Rain Water II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    using tii = tuple<int, int, int>;

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tii, vector<tii>, greater<tii>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m - 1][i], m - 1, i});
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        int res = 0;
        while (pq.size()) {
            auto [height, i, j] = pq.top();
            pq.pop();

            for (auto d : dirs) {
                int ti = i + d[0];
                int tj = j + d[1];
                if (ti < 0 or ti >= m or tj < 0 or tj >= n or visited[ti][tj])
                    continue;
                visited[ti][tj] = true;
                if (heightMap[ti][tj] < height)
                    res += height - heightMap[ti][tj];
                pq.push({max(height, heightMap[ti][tj]), ti, tj});
            }
        }
        return res;
    }
};