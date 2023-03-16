// 72. Edit Distance

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == word1.size())
            return word2.size() - j;

        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = dfs(word1, word2, i + 1, j + 1, dp);

        int ins = dfs(word1, word2, i, j + 1, dp);
        int del = dfs(word1, word2, i + 1, j, dp);
        int replace = dfs(word1, word2, i + 1, j + 1, dp);

        dp[i][j] = min(min(ins, del), replace) + 1;

        return dp[i][j];
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, 0, 0, dp);
    }
};

// redo
class Solution
{
    int dfs(string &word1, string &word2, int i, int j,
            vector<vector<int>> &dp)
    {
        if (i == word1.size())
            return word2.size() - j;

        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = dfs(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = min(
                              min(dfs(word1, word2, i, j + 1, dp),
                                  dfs(word1, word2, i + 1, j, dp)),
                              dfs(word1, word2, i + 1, j + 1, dp)) +
                          1;
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size(), -1));
        return dfs(word1, word2, 0, 0, dp);
    }
};