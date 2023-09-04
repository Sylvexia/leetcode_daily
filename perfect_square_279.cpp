// 279. Perfect Squares

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> dp;
    int dfs(int n)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int res = 1e9;
        for (int i = 1; i * i <= n; i++) {
            res = min(res, 1 + dfs(n - i * i));
        }
        return dp[n] = res;
    }

public:
    int numSquares(int n)
    {
        dp.resize(n + 1, -1);
        return dfs(n);
    }
};