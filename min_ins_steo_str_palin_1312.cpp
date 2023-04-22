// 1312. Minimum Insertion Steps to Make a String Palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[501][501];
    int dfs(int i, int j, string &s)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dfs(i + 1, j - 1, s);

        int begin = 1 + dfs(i, j - 1, s);
        int end = 1 + dfs(i + 1, j, s);
        return dp[i][j] = min(begin, end);
    }

public:
    int minInsertions(string s)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(0, s.size() - 1, s);
    }
};