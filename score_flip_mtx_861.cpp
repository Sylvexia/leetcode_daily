// 861. Score After Flipping Matrix

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++) {
            if (!grid[i][0]) {
                for (int j = 0; j < grid[0].size(); j++)
                    grid[i][j] ^= 1;
            }
        }

        for (int j = 0; j < grid[0].size(); j++) {
            int count_1 = 0;

            for (int i = 0; i < grid.size(); i++)
                count_1 += grid[i][j];

            if (count_1 < grid.size() - count_1) {
                for (int i = 0; i < grid.size(); i++)
                    grid[i][j] ^= 1;
            }
        }

        int res = 0;

        for (auto r : grid) {
            int local = 0;
            for (int c : r) {
                local = (local << 1) + c;
            }
            res += local;
        }

        return res;
    }
};