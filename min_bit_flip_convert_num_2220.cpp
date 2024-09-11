// 2220. Minimum Bit Flips to Convert Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xors = start ^ goal;
        int res = 0;
        while (xors) {
            xors &= (xors - 1);
            res++;
        }
        return res;
    }
};