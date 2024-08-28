// 1905. Count Sub Islands

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void dfs(int i,
             int j,
             vector<vector<int>> &grid2,
             vector<pair<int, int>> &col)
    {
        if (i < 0 or j < 0 or i >= grid2.size() or j >= grid2[0].size())
            return;

        if (!grid2[i][j])
            return;

        grid2[i][j] = 0;
        col.push_back({i, j});

        dfs(i + 1, j, grid2, col);
        dfs(i - 1, j, grid2, col);
        dfs(i, j + 1, grid2, col);
        dfs(i, j - 1, grid2, col);
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid1[i][j] or !grid2[i][j])
                    continue;

                vector<pair<int, int>> col;
                dfs(i, j, grid2, col);

                bool local = true;
                for (auto [i, j] : col) {
                    local &= grid1[i][j];
                }
                res += local;
            }
        }
        return res;
    }
};