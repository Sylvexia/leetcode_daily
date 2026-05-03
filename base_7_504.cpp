// 504. Base 7

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        int pos = abs(num);
        bool isNeg = num < 0;
        string res;
        while (pos > 0) {
            int rem = pos % 7;
            pos /= 7;
            res.push_back(rem + '0');
        }
        if (isNeg)
            res.push_back('-');
        return {res.rbegin(), res.rend()};
    }
};