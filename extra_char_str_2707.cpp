// 2707. Extra Characters in a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_set<string> u_set;
    int dp[51];

    int dfs(string &s, int start_i)
    {
        if (start_i >= s.size())
            return 0;

        if (dp[start_i] != -1)
            return dp[start_i];

        int res = 1 + dfs(s, start_i + 1);

        for (int num = 1; num <= s.size() - start_i; num++) {
            string sub = s.substr(start_i, num);
            if (u_set.find(sub) != u_set.end())
                res = min(res, dfs(s, start_i + num));
        }

        return dp[start_i] = res;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto &s : dictionary)
            u_set.insert(s);
        memset(dp, -1, sizeof(dp));

        return dfs(s, 0);
    }
};