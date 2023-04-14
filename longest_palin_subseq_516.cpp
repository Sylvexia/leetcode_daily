// 516. Longest Palindromic Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[1001][1001];
    int dfs(int l, int r, string &s)
    {
        if (l == r)
            return 1;

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = 0;

        if (s[l] == s[r])
            return dp[l][r] = dfs(l + 1, r - 1, s) + 2;

        return dp[l][r] = max(dfs(l + 1, r, s), dfs(l, r - 1, s));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(0, s.size() - 1, s);
    }
};