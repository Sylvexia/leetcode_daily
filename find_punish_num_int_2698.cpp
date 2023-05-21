// 2698. Find the Punishment Number of an Integer

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool can_make(int square, int i)
    {
        if (i < 0 or square < i)
            return false;
        if (square == i)
            return true;
        return can_make(square / 10, i - square % 10) or can_make(square / 100, i - square % 100) or
               can_make(square / 1000, i - square % 1000);
    }

public:
    int punishmentNumber(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int square = i * i;
            if (can_make(square, i))
                res += square;
        }
        return res;
    }
};