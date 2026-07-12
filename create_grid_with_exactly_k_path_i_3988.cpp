// 3988. Create Grid With Exactly K Paths I

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> createGrid(int m, int n, int k)
    {
        vector<string> grid(m, string(n, '#'));

        auto build = [&](const vector<string>& gadget) {
            int h = gadget.size();
            int w = gadget[0].size();

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    grid[i][j] = gadget[i][j];
                }
            }

            int row = h - 1;
            int col = w - 1;

            for (int j = col; j < n; j++)
                grid[row][j] = '.';

            for (int i = row; i < m; i++)
                grid[i][n - 1] = '.';
        };

        if (k == 1) {
            for (int j = 0; j < n; j++)
                grid[0][j] = '.';

            for (int i = 0; i < m; i++)
                grid[i][n - 1] = '.';

            return grid;
        }

        if (k == 2) {
            if (m < 2 || n < 2)
                return {};

            build({
                "..",
                ".."
            });
            return grid;
        }

        if (k == 3) {
            if (m >= 2 && n >= 3) {
                build({
                    "...",
                    "..."
                });
                return grid;
            }

            if (m >= 3 && n >= 2) {
                build({
                    "..",
                    "..",
                    ".."
                });
                return grid;
            }

            return {};
        }

        if (m >= 2 && n >= 4) {
            build({
                "....",
                "...."
            });
            return grid;
        }

        if (m >= 4 && n >= 2) {
            build({
                "..",
                "..",
                "..",
                ".."
            });
            return grid;
        }

        if (m >= 3 && n >= 3) {
            build({
                "..#",
                "...",
                "#.."
            });
            return grid;
        }

        return {};
    }
};