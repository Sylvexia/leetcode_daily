// 583. Delete Operation for Two Strings

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = word1.size(), m = word2.size();

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (size_t i = 0; i < word1.size(); i++) {
            for (size_t j = 0; j < word2.size(); j++) {
                if (word1[i] == word2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        int common = dp[word1.size()][word2.size()];

        return word1.size() - common + word2.size() - common;
    }
};