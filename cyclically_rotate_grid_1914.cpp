// 1914. Cyclically Rotating a Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int d = 0; d < min(m, n) / 2; d++) {
            vector<int> rot;
            for (int i = 0; i < m - 1 - 2 * d; i++)
                rot.push_back(grid[i + d][0 + d]);
            for (int i = 0; i < n - 1 - 2 * d; i++)
                rot.push_back(grid[m - 1 - d][i + d]);
            for (int i = 0; i < m - 1 - 2 * d; i++)
                rot.push_back(grid[m - 1 - i - d][n - 1 - d]);
            for (int i = 0; i < n - 1 - 2 * d; i++)
                rot.push_back(grid[0 + d][n - 1 - i - d]);

            size_t shift = k % rot.size();
            std::rotate(rot.begin(),
                        rot.begin() + (rot.size() - shift) % rot.size(),
                        rot.end());
            auto it = rot.begin();

            for (int i = 0; i < m - 1 - 2 * d; i++)
                grid[i + d][0 + d] = *it++;
            for (int i = 0; i < n - 1 - 2 * d; i++)
                grid[m - 1 - d][i + d] = *it++;
            for (int i = 0; i < m - 1 - 2 * d; i++)
                grid[m - 1 - i - d][n - 1 - d] = *it++;
            for (int i = 0; i < n - 1 - 2 * d; i++)
                grid[0 + d][n - 1 - i - d] = *it++;
        }

        return grid;
    }
};