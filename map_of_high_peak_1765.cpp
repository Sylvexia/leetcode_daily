// 1765. Map of Highest Peak

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    using pii = pair<int, int>;
    vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pii> q;
        int curLevel = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = curLevel;
                    q.push({i, j});
                }
            }
        }

        while (q.size()) {
            curLevel++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [cur_i, cur_j] = q.front();
                q.pop();

                for (auto [di, dj] : dirs) {
                    int ti = cur_i + di;
                    int tj = cur_j + dj;
                    if (ti < 0 or ti >= m or tj < 0 or tj >= n or
                        res[ti][tj] != -1)
                        continue;

                    res[ti][tj] = curLevel;
                    q.push({ti, tj});
                }
            }
        }
        return res;
    }
};