// 2140. Solving Questions With Brainpower

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> m_q;
    vector<long long> m_dp;

    long long dfs(int i)
    {
        if (i >= m_q.size())
            return 0;

        if (m_dp[i] != -1)
            return m_dp[i];

        long long res = max(dfs(i + 1),
                            (m_q[i][0] + dfs(m_q[i][1] + i + 1)));

        return m_dp[i] = res;
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        m_dp.resize(questions.size() + 1, -1);
        m_q = move(questions);
        return dfs(0);
    }
};