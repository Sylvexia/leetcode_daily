// 1277. Count Square Submatrices with All Ones

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1)
                    dp[i + 1][j + 1] =
                        1 + min({dp[i][j + 1], dp[i + 1][j], dp[i][j]});
                res += dp[i + 1][j + 1];
            }
        }
        return res;
    }
};