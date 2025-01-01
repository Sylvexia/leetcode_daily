// 2224. Minimum Number of Operations to Convert Time

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline int getMin(string &str)
    {
        return 600 * str[0] + 60 * str[1] + 10 * str[3] + str[4];
    }

public:
    int convertTime(string current, string correct)
    {
        int diff = getMin(correct) - getMin(current);
        int res = 0;
        array<int, 4> divs{60, 15, 5, 1};
        for (int d : divs) {
            res += diff / d;
            diff %= d;
        }
        return res;
    }
};