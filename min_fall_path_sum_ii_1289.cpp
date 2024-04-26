// 1289. Minimum Falling Path Sum II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < grid.size() - 1; i++) {
            int min_1 = INT_MAX, min_2 = INT_MAX;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < min_1) {
                    min_2 = min_1;
                    min_1 = grid[i][j];
                } else if (grid[i][j] < min_2)
                    min_2 = grid[i][j];
            }

            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == min_1)
                    grid[i + 1][j] += min_2;
                else
                    grid[i + 1][j] += min_1;
            }
        }
        return *min_element(grid[m - 1].begin(), grid[m - 1].end());
    }
};