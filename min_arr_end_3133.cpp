// 3133. Minimum Array End

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--;

        bitset<64> res(x);
        for (int i = 0; n > 0; i++) {
            if (!res[i]) {
                res[i] = n & 1;
                n >>= 1;
            }
        }
        return res.to_ullong();
    }
};