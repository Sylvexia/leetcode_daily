// 402. Remove K Digits

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res;
        for (char digit : num) {
            while (k > 0 and !res.empty() and digit < res.back()) {
                res.pop_back();
                k--;
            }
            if (!res.empty() || digit != '0')
                res.push_back(digit);
        }

        while (!res.empty() and k--)
            res.pop_back();

        return (res == "") ? "0" : res;
    }
};