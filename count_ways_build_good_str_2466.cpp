// 2466. Count Ways To Build Good Strings

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> m_dp;
    int m_low;
    int m_high;
    int m_zero;
    int m_one;
    int mod = 1000000007;

    int dfs(int i)
    {
        if (i == 0)
            return 1;
        if (i < 0)
            return 0;

        if (m_dp[i] != -1)
            return m_dp[i];

        long long res = 0;
        res = dfs(i - m_zero) + dfs(i - m_one);
        return m_dp[i] = res % mod;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        m_dp.resize(high + 1, -1);
        m_low = move(low);
        m_high = move(high);
        m_zero = move(zero);
        m_one = move(one);

        int res = 0;
        for (int i = m_low; i <= m_high; i++)
            res = (res + dfs(i)) % mod;

        return res;
    }
};

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int n = high + 1;
        constexpr int mod = 1e9 + 7;
        int dp[n];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % mod;
        }

        int res = 0;
        for (int i = low; i <= high; i++)
            res = (res + dp[i]) % mod;

        return res;
    }
};