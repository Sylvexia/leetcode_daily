// 1404. Number of Steps to Reduce a Number in Binary Representation to One

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numSteps(string s)
    {
        int res = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            res++;
            if ((s[i] - '0' + carry) == 1) {
                carry = 1;
                res++;
            }
        }
        return res + carry;
    }
};