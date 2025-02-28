// 1092. Shortest Common Supersequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        string res = "";
        int i = n, j = m;

        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                res += str1[i - 1];
                i--;
            } else {
                res += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            res += str1[i - 1];
            i--;
        }

        while (j > 0) {
            res += str2[j - 1];
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};