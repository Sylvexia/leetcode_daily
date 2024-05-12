// 2373. Largest Local Values in a Matrix

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, INT_MIN));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int local_max = INT_MIN;

                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++)
                        local_max = max(local_max, grid[i + r][j + c]);
                }

                res[i][j] = local_max;
            }
        }
        return res;
    }
};