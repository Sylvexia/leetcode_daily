// 790. Domino and Tromino Tiling

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<int> dp;
    const int mod = 1e9 + 7;

public:
    int dfs(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int res = 0;
        res += dfs(n - 1) + dfs(n - 2);
        res %= mod;
        for (int i = n - 3; i >= 0; i--) {
            res += (2 * dfs(i)) % mod;
            res %= mod;
        }
        dp[n] = res;
        return res;
    }
    int numTilings(int n)
    {
        dp.resize(n + 1, -1);
        return dfs(n);
    }
};

class Solution
{
    vector<int> dp;
    const int mod = 1e9 + 7;

public:
    int dfs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = ((2 * dfs(n - 1)) % mod + (dfs(n - 3)) % mod) % mod;
    }
    int numTilings(int n)
    {
        dp.resize(n + 1, -1);
        return dfs(n);
    }
};