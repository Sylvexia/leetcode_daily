// 441. Arranging Coins

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool condition(int m, int n) { return ((long long) m * (m + 1) / 2) > n; }

public:
    int arrangeCoins(int n)
    {
        int l = 0;
        long long r = (long long) n + 1;

        while (l < r) {
            long long m = l + (r - l) / 2;
            if (condition(m, n))
                r = m;
            else
                l = m + 1;
        }
        return l - 1;
    }
};