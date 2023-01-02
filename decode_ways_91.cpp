// 91. Decode Ways

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(string &s, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;

        if (dp[i] > -1)
            return dp[i];

        int res = 0;

        if (s[i] != '0')
            res += dfs(s, i + 1, dp);

        if ((i + 1 < s.size()) &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            res += dfs(s, i + 2, dp);

        return dp[i] = res;
    }

public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }
};