// 139. Word Break

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string &s, vector<string> &wordDict)
    {
        unordered_set<string> u_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for (int end = 1; end <= s.size(); end++)
        {
            for (int start = end - 1; start >= 0; start--)
            {
                if (dp[start])
                {
                    if (u_set.find(s.substr(start, end - start)) != u_set.end())
                    {
                        dp[end] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};