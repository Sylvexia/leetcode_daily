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
    bool isPerfectSquare(int num)
    {
        long long l = 1;
        long long r = (1 << 16) - 1;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (m * m >= num)
                r = m;
            else
                l = m + 1;
        }

        return l * l == num;
    }
};