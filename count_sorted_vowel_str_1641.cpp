// 1641. Count Sorted Vowel Strings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(int n, int k)
    {
        if (n == 0)
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        int res = 0;
        for (int i = k; i < 5; i++)
            res += dfs(n - 1, i);

        return res;
    }

public:
    int countVowelStrings(int n)
    {
        dp.resize(n + 1, vector<int>(5, -1));
        return dfs(n, 0);
    }
};