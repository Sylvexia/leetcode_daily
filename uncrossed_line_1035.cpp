// 1035. Uncrossed Lines

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> m_nums1;
    vector<int> m_nums2;
    vector<vector<int>> m_dp;

    int dfs(int i, int j)
    {
        if (i >= m_nums1.size() or j >= m_nums2.size())
            return 0;

        if (m_dp[i][j] != -1)
            return m_dp[i][j];

        int res = 0;

        if (m_nums1[i] == m_nums2[j])
            res = 1 + dfs(i + 1, j + 1);

        res = max({res, dfs(i + 1, j), dfs(i, j + 1)});

        return m_dp[i][j] = res;
    }

public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        m_dp.resize(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));
        m_nums1 = move(nums1);
        m_nums2 = move(nums2);
        return dfs(0, 0);
    }
};

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size() + 1, n = nums2.size() + 1;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                dp[i][j] = max({
                    (nums1[i - 1] == nums2[j - 1])
                        ? 1 + dp[i - 1][j - 1]
                        : 0,
                    dp[i][j - 1],
                    dp[i - 1][j],
                });
            }
        }

        return dp[m - 1][n - 1];
    }
};