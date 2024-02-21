// 69. Sqrt(x)

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long long int l = 0, r = (long long int) x + 1;
        while (l < r) {
            long long int m = l + (r - l) / 2;
            if (m * m > x)
                r = m;
            else
                l = m + 1;
        }
        return l - 1;
    }
};