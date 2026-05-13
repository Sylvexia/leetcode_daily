// 807. Max Increase to Keep City Skyline

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<int> rowMax(n, 0);
        vector<int> colMax(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }

        return res;
    }
};