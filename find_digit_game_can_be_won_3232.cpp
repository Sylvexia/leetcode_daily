// 3232. Find if Digit Game Can Be Won

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int s = 0, d = 0;
        for (int n : nums) {
            if (n > 9)
                d+=n;
            else
                s+=n;
        }
        return d != s;
    }
};