// 959. Regions Cut By Slashes

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void mark(int i, int j, vector<vector<int>> &upscale)
    {
        if (i < 0 or j < 0 or i >= upscale.size() or j >= upscale[0].size())
            return;
        if (upscale[i][j] == 1)
            return;

        upscale[i][j] = 1;
        mark(i + 1, j, upscale);
        mark(i - 1, j, upscale);
        mark(i, j + 1, upscale);
        mark(i, j - 1, upscale);
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int m = 3 * n;
        vector<vector<int>> upscale(m, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '\\') {
                    upscale[3 * i][3 * j] = 1;
                    upscale[3 * i + 1][3 * j + 1] = 1;
                    upscale[3 * i + 2][3 * j + 2] = 1;
                } else if (grid[i][j] == '/') {
                    upscale[3 * i + 2][3 * j] = 1;
                    upscale[3 * i + 1][3 * j + 1] = 1;
                    upscale[3 * i][3 * j + 2] = 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (upscale[i][j] == 0) {
                    res++;
                    mark(i, j, upscale);
                }
            }
        }
        return res;
    }
};