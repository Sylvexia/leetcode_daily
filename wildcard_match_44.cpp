// 44. Wildcard Matching

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    string m_s;
    string m_p;

    bool dfs(int s_i, int p_i, vector<vector<int>> &dp)
    {
        if (p_i == m_p.size())
            return (s_i == m_s.size());
        if (dp[s_i][p_i] != -1)
            return dp[s_i][p_i];

        if (s_i < m_s.size() and (m_p[p_i] == '?' or m_s[s_i] == m_p[p_i]))
            return dp[s_i][p_i] = dfs(s_i + 1, p_i + 1, dp);
        if (m_p[p_i] == '*')
            return dp[s_i][p_i] =
                       (dfs(s_i, p_i + 1, dp) |
                        (s_i < m_s.size() and dfs(s_i + 1, p_i, dp)));

        return dp[s_i][p_i] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        m_s = move(s);
        m_p = move(p);
        vector<vector<int>> dp(m_s.size() + 1, vector<int>(m_p.size() + 1, -1));

        return dfs(0, 0, dp);
    }
};