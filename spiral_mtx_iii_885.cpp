// 885. Spiral Matrix III

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows,
                                        int cols,
                                        int rStart,
                                        int cStart)
    {
        int dirs[5] = {0, 1, 0, -1, 0};
        int step_max = 1;
        int step_cur = 0;
        int dir_i = 0;
        int change = 0;
        vector<vector<int>> res;

        while (res.size() < rows * cols) {
            if (rStart < rows and cStart < cols and
                rStart >= 0 and cStart >= 0) {
                res.push_back({rStart, cStart});
            }
            rStart += dirs[dir_i];
            cStart += dirs[dir_i + 1];

            step_cur++;
            if (step_cur == step_max) {
                dir_i = (dir_i + 1) % 4;
                step_cur = 0;
                change++;
                if (change % 2 == 0)
                    step_max++;
            }
        }
        return res;
    }
};