// 263. Ugly Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;

        int prev = -1;
        while (n != prev) {
            prev = n;
            if (n % 2 == 0)
                n /= 2;
            if (n % 3 == 0)
                n /= 3;
            if (n % 5 == 0)
                n /= 5;
        }

        return n == 1;
    }
};