// 2999. Count the Number of Powerful Integers

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
    long long dp[16] = {};
    long long dfs(int i, char limit, string &n, string &s)
    {
        if (n.size() < s.size())
            return 0;
        if (i == n.size() - s.size())
            return n.substr(i) >= s;

        int digits = min(limit, n[i]) - '1' + (i > 0);

        return dp[n.size() - i - 1] * digits +
               (n[i] < limit ? dfs(i + 1, limit, n, s) : 0);
    }

public:
    long long numberOfPowerfulInt(long long start,
                                  long long finish,
                                  int limit,
                                  string s)
    {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);

        for (int i = s.size(); i < finishStr.size(); i++)
            dp[i] = i == s.size() ? 1 : dp[i - 1] * (limit + 1);

        return dp[finishStr.size() - 1] + dfs(0, '1' + limit, finishStr, s) -
               (dp[startStr.size() - 1] + dfs(0, '1' + limit, startStr, s));
    }
};