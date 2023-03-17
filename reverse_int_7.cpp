// 7. Reverse Integer

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            if (res > INT_MAX / 10 or res < INT_MIN / 10)
                return 0;
                
            int last = x % 10;
            x /= 10;
            res = res * 10 + last;
        }
        return res;
    }
};