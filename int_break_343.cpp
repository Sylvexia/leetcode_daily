// 343. Integer Break

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        int res = 1;
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else {
            while (n > 4) {
                n -= 3;
                res *= 3;
            }
            return res * n;
        }
    }
};