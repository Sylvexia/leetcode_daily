// 1416. Restore The Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[100001];
    int dfs(int start, string &s, int k)
    {
        if (start == s.size())
            return 1;
        if (start > s.size())
            return 0;

        if (s[start] == '0')
            return 0;

        if (dp[start] != -1)
            return dp[start];

        int res = 0;
        long num = 0;

        for (int i = start; i < s.size(); i++)
        {
            num = num * 10 + s[i] - '0';
            if (num > k)
                break;
            res += dfs(i + 1, s, k);
            res %= 1000000007;
        }
        return dp[start] = res;
    }

public:
    int numberOfArrays(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(0, s, k);
    }
};