// 1545. Find Kth Bit in Nth Binary String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
    char solve(int k, int count)
    {
        if (k == 1)
            return count % 2 ? '1' : '0';
        if (((k) & (k - 1)) == 0)
            return count % 2 ? '0' : '1';
        int next_k = pow(2, int(log2(k)) + 1) - k;
        return solve(next_k, count + 1);
    }

public:
    char findKthBit(int n, int k) { return solve(k, 0); }
};