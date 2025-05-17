// 2901. Longest Unequal Adjacent Groups Subsequence II

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    bool oneDiff(string &w1, string &w2)
    {
        if (w1.size() != w2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < w1.size(); i++)
            diff += w1[i] != w2[i];
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words,
                                                vector<int> &groups)
    {
        int n = groups.size();
        vector<int> dp(n + 1), prev(n, -1);
        int maxI = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] and oneDiff(words[i], words[j]) and
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            maxI = max(maxI, dp[i]);
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (maxI == dp[i]) {
                while (i != -1) {
                    res.push_back(words[i]);
                    i = prev[i];
                }
                break;
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};