// 1048. Longest String Chain

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    struct Comp {
        inline bool operator()(const string &str1, const string &str2)
        {
            return str1.size() < str2.size();
        }
    };

public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), Comp());

        unordered_map<string, int> dp;
        int res = 0;
        for (auto &w : words) {
            for (int i = 0; i < w.size(); i++) {
                string temp = w.substr(0, i) + w.substr(i + 1);
                dp[w] =
                    max(dp[w], dp.find(temp) == dp.end() ? 1 : dp[temp] + 1);
            }
            res = max(res, dp[w]);
        }

        return res;
    }
};