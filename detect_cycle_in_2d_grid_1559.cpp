// 1559. Detect Cycles in 2D Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
    int m, n;
    vector<vector<uint8_t>> cache;
    static constexpr int dirs[4][2] = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    bool dfs(int i, int j, int pi, int pj, const vector<vector<char>> &grid)
    {
        cache[i][j] = 1;

        for (auto &[di, dj] : dirs) {
            int ti = i + di;
            int tj = j + dj;

            if (ti < 0 || tj < 0 || ti >= m || tj >= n)
                continue;

            if (ti == pi && tj == pj)
                continue;

            if (grid[ti][tj] == grid[i][j]) {
                if (cache[ti][tj] || dfs(ti, tj, i, j, grid))
                    return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        cache.assign(m, vector<uint8_t>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!cache[i][j] && dfs(i, j, -1, -1, grid))
                    return true;
            }
        }
        return false;
    }
};