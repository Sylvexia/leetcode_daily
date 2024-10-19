// 1545. Find Kth Bit in Nth Binary String

#include <bits/stdc++.h>

using namespace std;

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