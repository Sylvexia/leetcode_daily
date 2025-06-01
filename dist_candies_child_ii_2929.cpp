// 2929. Distribute Candies Among Children II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    long long comb(int n)
    {
        if (n < 0)
            return 0;
        return (long long) (n) * (n - 1) / 2;
    }

public:
    long long distributeCandies(int n, int limit)
    {
        return comb(n + 2) - 3 * comb(n - (limit + 1) + 2) +
               3 * comb(n - 2 * (limit + 1) + 2) -
               comb(n - 3 * (limit + 1) + 2);
    }
};