// 97. Interleaving String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    string m_s1, m_s2, m_s3;
    vector<vector<int>> m_dp;

    bool dfs(int i, int j)
    {
        if (i == m_s1.size() and j == m_s2.size() and i + j >= m_s3.size())
            return true;

        if (i + j >= m_s3.size())
            return false;

        if (m_dp[i][j] != -1)
            return m_dp[i][j];

        return m_dp[i][j] = (m_s1[i] == m_s3[i + j] and dfs(i + 1, j)) or
                            (m_s2[j] == m_s3[i + j] and dfs(i, j + 1));
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if ((s1.size() + s2.size()) != s3.size())
            return false;

        m_s1 = move(s1);
        m_s2 = move(s2);
        m_s3 = move(s3);
        m_dp = move(vector<vector<int>>(m_s1.size() + 1,
                                        vector<int>(m_s2.size() + 1, -1)));

        return dfs(0, 0);
    }
};