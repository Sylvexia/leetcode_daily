// 2864. Maximum Odd Binary Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int count = 0;
        for (char c : s)
            count += (c == '1');

        string res;
        for (int i = count - 1; i > 0; i--)
            res.push_back('1');
        for (int i = s.size() - res.size() - 1; i > 0; i--)
            res.push_back('0');
        return res + '1';
    }
};