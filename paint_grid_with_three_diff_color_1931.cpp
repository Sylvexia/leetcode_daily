// 1931. Painting a Grid With Three Different Colors

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[1001][1024] = {};
    int dfs(int m, int n, int i, int j, int cur, int prev)
    {
        if (i == m)
            return dfs(m, n, 0, j + 1, 0, cur);
        if (j == n)
            return 1;
        if (i == 0 and dp[j][prev])
            return dp[j][prev];

        int res = 0;
        int up = i == 0 ? 0 : (cur >> ((i - 1) << 1) & 3);
        int left = prev >> (i << 1) & 3;

        for (int k = 1; k <= 3; k++) {
            if (k != left and k != up)
                res = (res + dfs(m, n, i + 1, j, cur + (k << (i << 1)), prev)) %
                                (1000000007);
        }
        if (i == 0)
            dp[j][prev] = res;
        return res;
    }

public:
    int colorTheGrid(int m, int n) { return dfs(m, n, 0, 0, 0, 0); }
};