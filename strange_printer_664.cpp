// 664. Strange Printer

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(int i, int j, string &s)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        res = 1 + dfs(i, j - 1, s);

        char last = s[j];
        for (int idx = i; idx < j; idx++) {
            if (s[idx] == last)
                res = min(res, dfs(i, idx, s) + dfs(idx + 1, j - 1, s));
        }

        return dp[i][j] = res;
    }

public:
    int strangePrinter(string s)
    {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(0, n - 1, s);
    }
};