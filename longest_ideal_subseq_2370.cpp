// 2370. Longest Ideal Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int dp[26] = {0};
        int res = 1;
        for (char ch : s) {
            int i = ch - 'a';
            dp[i] += 1;
            for (int j = max(0, i - k); j <= min(25, i + k); j++) {
                if (j != i)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};