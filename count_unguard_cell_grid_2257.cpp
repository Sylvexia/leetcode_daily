// 2257. Count Unguarded Cells in the Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countUnguarded(int m,
                       int n,
                       vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (auto &w : walls) {
            int i = w[0];
            int j = w[1];
            dp[i][j] = 1;
        }
        for (auto &g : guards) {
            int i = g[0];
            int j = g[1];
            dp[i][j] = 1;
        }

        for (auto &g : guards) {
            int i = g[0];
            int j = g[1];
            for (int y = i + 1; y < m; y++) {
                if (dp[y][j] == 1)
                    break;
                dp[y][j] = 2;
            }
            for (int x = j + 1; x < n; x++) {
                if (dp[i][x] == 1)
                    break;
                dp[i][x] = 2;
            }
            for (int y = i - 1; y >= 0; y--) {
                if (dp[y][j] == 1)
                    break;
                dp[y][j] = 2;
            }
            for (int x = j - 1; x >= 0; x--) {
                if (dp[i][x] == 1)
                    break;
                dp[i][x] = 2;
            }
        }

        int res = 0;
        for (auto &r : dp) {
            for (auto c : r)
                res += (c == 0);
        }
        return res;
    }
};