// 1318. Minimum Flips to Make a OR b Equal to c

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    inline int count_bit(int num)
    {
        int count = 0;
        while (num) {
            num &= num - 1;
            count++;
        }
        return count;
    }

public:
    int minFlips(int a, int b, int c)
    {
        int must_flip_mask = (a | b) ^ c;
        return count_bit(must_flip_mask) + count_bit(a & b & (must_flip_mask));
    }
};