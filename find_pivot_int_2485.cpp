// 2485. Find the Pivot Integer

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int pivotInteger(int n)
    {
        int l = 1, r = (1 + n) * n / 2;
        int accum = 1;
        while (l <= r) {
            if (l == r)
                return accum;
            else if (l > r)
                return -1;
            else {
                r -= accum;
                accum++;
                l += accum;
            }
        }
        return -1;
    }
};