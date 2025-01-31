// 827. Making A Large Island

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getVal(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
            return 0;
        return grid[i][j];
    }
    int dfs(int i, int j, int color, vector<vector<int>> &grid)
    {
        if (getVal(i, j, grid) != 1)
            return 0;

        grid[i][j] = color;

        return dfs(i + 1, j, color, grid) + dfs(i - 1, j, color, grid) +
               dfs(i, j + 1, color, grid) + dfs(i, j - 1, color, grid) + 1;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colorSize{0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int curSize = dfs(i, j, colorSize.size(), grid);
                    colorSize.push_back(curSize);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    continue;

                unordered_set<int> colors{
                    getVal(i - 1, j, grid), getVal(i + 1, j, grid),
                    getVal(i, j + 1, grid), getVal(i, j - 1, grid)};

                int total = 1;
                for (int c : colors)
                    total += colorSize[c];

                res = max(res, total);
            }
        }

        return res == 0 ? m * n : res;
    }
};