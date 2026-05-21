// 926. Flip String to Monotone Increasing

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int ones = 0;
        int res = 0;

        for (char ch : s) {
            if (ch == '1')
                ones++;
            else {
                res++;
                res = min(res, ones);
            }
        }
        return res;
    }
};