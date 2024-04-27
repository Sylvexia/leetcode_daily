// 514. Freedom Trail

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> m_pos;
    vector<vector<int>> dp;
    string m_ring;
    string m_key;

public:
    int dfs(int i, int j)
    {
        if (j == m_key.size())
            return 0;
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int best = INT_MAX;
        for (int next : m_pos[m_key[j] - 'a']) {
            int diff = abs(i - next);
            best = min(best,
                       min(diff, int(m_ring.size() - diff)) + dfs(next, j + 1));
        }
        dp[i][j] = best + 1;
        return dp[i][j];
    }
    int findRotateSteps(string ring, string key)
    {
        m_pos.resize(26);
        for (int i = 0; i < ring.size(); i++)
            m_pos[ring[i] - 'a'].push_back(i);
        dp.resize(ring.size(), vector<int>(key.size(), INT_MAX));
        m_ring = ring;
        m_key = key;
        return dfs(0, 0);
    }
};