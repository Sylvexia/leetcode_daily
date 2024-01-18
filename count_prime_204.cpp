// 204. Count Primes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        int res = 0;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < n; i++) {
            if (dp[i] == 0)
                res++;
            else
                continue;

            for (int composite = i; composite <= n; composite += i)
                dp[composite] = 1;
        }
        return res;
    }
};