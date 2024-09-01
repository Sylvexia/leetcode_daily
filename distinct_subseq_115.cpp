// 115. Distinct Subsequences

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dp[1001][1001];
    int dfs(int i, int j, string &s, string &t)
    {
        if (j == t.size())
            return 1;
        if (i >= s.size() or j >= t.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = dfs(i + 1, j, s, t);
        if (s[i] == t[j])
            res += dfs(i + 1, j + 1, s, t);
        return dp[i][j] = res;
    }

public:
    int numDistinct(string s, string t)
    {
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++)
                dp[i][j] = -1;
        }
        return dfs(0, 0, s, t);
    }
};