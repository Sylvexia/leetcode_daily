#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int helper(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        dp[n] = helper(n - 2, dp) + helper(n - 1, dp);
        return dp[n];
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(46);
        for (int &ele : dp)
            ele = -1;

        dp[1] = 1;
        dp[2] = 2;

        return helper(n, dp);
    }
};