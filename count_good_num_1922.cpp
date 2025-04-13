// 1922. Count Good Numbers

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    const long long MOD = 1e9 + 7;

public:
    int countGoodNumbers(long long n)
    {
        // 5 * 4 * 5 * 4 = 5 ^ ( (n + 1) / 2) * 4 ^ ( n / 2 )
        long long pow5 = (n + 1) / 2;
        long long pow4 = (n / 2);

        long long res = 1;
        long long curFive = 5;
        while (pow5) {
            if (pow5 & 1)
                res *= curFive;
            curFive *= curFive;
            pow5 = pow5 >> 1;

            curFive %= MOD;
            res %= MOD;
        }

        long long curFour = 4;
        while (pow4) {
            if (pow4 & 1)
                res *= curFour;
            curFour *= curFour;
            pow4 = pow4 >> 1;

            curFour %= MOD;
            res %= MOD;
        }
        return res;
    }
};