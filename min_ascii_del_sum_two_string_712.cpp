// 712. Minimum ASCII Delete Sum for Two Strings

#include <bits/stdc++.h>
#include <climits>
#include <cstdint>

using namespace std;

class Solution
{
    int dp[1001][1001];
    int dfs(int i, int j, string &s1, string &s2)
    {
        if (i >= s1.size()) {
            int sum = 0;
            for (int cur = j; cur < s2.size(); cur++)
                sum += (int) s2[cur];
            return sum;
        }

        if (j >= s2.size()) {
            int sum = 0;
            for (int cur = i; cur < s1.size(); cur++)
                sum += (int) s1[cur];
            return sum;
        }

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = dfs(i + 1, j + 1, s1, s2);

        return dp[i][j] = min(dfs(i, j + 1, s1, s2) + (int) s2[j],
                              dfs(i + 1, j, s1, s2) + (int) s1[i]);
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++)
                dp[i][j] = INT_MAX;
        return dfs(0, 0, s1, s2);
    }
};