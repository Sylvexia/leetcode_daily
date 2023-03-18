// 50. Pow(x, n)

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 1)
            return 1;
        if (x == -1)
            return (n % 2 == 0) ? 1 : -1;
        if (n == 0)
            return 1;
        if (n == INT_MIN)
            return 0;
        if (n < 0)
            return 1 / myPow(x, -n);

        double res = 1;

        while (n > 0)
        {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }

        return res;
    }
};