// 1639. Number of Ways to Form a Target String Given a Dictionary

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    long long dfs(int t, int w, vector<string> &words, string &target,
                  vector<vector<long long>> &dp)
    {
        if (t >= target.size())
            return 1;

        if (w >= words[0].size())
            return 0;

        if (dp[t][w] != -1)
            return dp[t][w];

        long long ret = 0;

        for (auto word : words)
        {
            if (word[w] == target[t])
                ret += dfs(t + 1, w + 1, words, target, dp) % 1000000007;
        }

        ret += dfs(t, w + 1, words, target, dp) % 1000000007;

        return dp[t][w] = ret % 1000000007;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        vector<vector<long long>> dp(target.size(), vector<long long>(words[0].size(), -1));
        long long res = dfs(0, 0, words, target, dp) % 1000000007;
        return res;
    }
}; // this get tle

class Solution
{
    long long dfs(int t, int w, vector<string> &words, string &target,
                  vector<vector<long long>> &dp, vector<vector<long>> &freq)
    {
        if (t >= target.size())
            return 1;

        if (w >= words[0].size())
            return 0;

        if (dp[t][w] != -1)
            return dp[t][w];

        long long ret = 0;

        ret += dfs(t, w + 1, words, target, dp, freq) % 1000000007;
        ret += freq[w][target[t] - 'a'] *
               dfs(t + 1, w + 1, words, target, dp, freq) % 1000000007;

        return dp[t][w] = ret % 1000000007;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        vector<vector<long long>> dp(target.size(), vector<long long>(words[0].size(), -1));
        vector<vector<long>> freq(words[0].size(), vector<long>(26, 0));

        for (auto w : words)
        {
            for (int i = 0; i < words[0].size(); i++)
            {
                int ch = w[i] - 'a';
                freq[i][ch]++;
            }
        }
        long long res = dfs(0, 0, words, target, dp, freq) % 1000000007;
        return res;
    }
}; // fuck this passed uwu