// 1137. N-th Tribonacci Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[40];
    int tri_helper(int n)
    {
        if (n <= 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = tri_helper(n - 3) + tri_helper(n - 2) + tri_helper(n - 1);
    }

public:
    int tribonacci(int n)
    {
        for (auto& ele : dp)
            ele = -1;

        return tri_helper(n);
    }
};