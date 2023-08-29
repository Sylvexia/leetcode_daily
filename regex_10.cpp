// 10. Regular Expression Matching

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    string m_s;
    string m_p;
    int dp[21][21];

public:
    bool dfs(int s_i, int p_i)
    {
        if (p_i == m_p.size())
            return s_i == m_s.size();

        if (dp[s_i][p_i] != -1)
            return dp[s_i][p_i];

        bool res = false;

        bool first_match =
            (s_i < m_s.size()) and ((m_s[s_i] == m_p[p_i]) || (m_p[p_i] == '.'));

        if (p_i + 1 < m_p.size() and m_p[p_i + 1] == '*')
            res = dfs(s_i, p_i + 2) or (first_match and dfs(s_i + 1, p_i));
        else
            res = first_match && dfs(s_i + 1, p_i + 1);

        dp[s_i][p_i] = res;
        return res;
    }

public:
    bool isMatch(string s, string p)
    {
        m_s = move(s);
        m_p = move(p);

        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++)
                dp[i][j] = -1;
        }

        return dfs(0, 0);
    }
};

int main()
{
    string s{"ab"};
    string p(".*c");

    Solution sol;

    cout << sol.isMatch(s, p);
}