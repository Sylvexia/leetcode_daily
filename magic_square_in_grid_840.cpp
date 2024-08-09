// 840. Magic Squares In Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int r = 0; r < (int) grid.size() - 2; r++) {
            for (int c = 0; c < (int) grid[0].size() - 2; c++) {
                unordered_set<int> u_set;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        u_set.insert(grid[r + i][c + j]);
                    }
                }

                int target =
                    grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];

                if (target !=
                    (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c]))
                    goto END;

                for (int i = 1; i <= 9; i++)
                    if (!u_set.count(i)) {
                        goto END;
                    }

                for (int i = 0; i < 3; i++) {
                    int local = 0;
                    for (int j = 0; j < 3; j++) {
                        local += grid[r + i][c + j];
                    }
                    if (local != target)
                        goto END;
                }

                for (int j = 0; j < 3; j++) {
                    int local = 0;
                    for (int i = 0; i < 3; i++)
                        local += grid[r + i][c + j];
                    if (local != target)
                        goto END;
                }

                res++;
            END:;
            }
        }
        return res;
    }
};