// 367. Valid Perfect Square

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";

        unsigned int n = num;
        string res;

        while (n > 0) {
            int digit = n & 0xf;
            char ch = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
            res.push_back(ch);
            n >>= 4;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};