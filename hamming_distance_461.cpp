// 461. Hamming Distance

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int xor_num = x ^ y;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int lsb = xor_num >> i;
            res += lsb & 1;
        }
        return res;
    }
};