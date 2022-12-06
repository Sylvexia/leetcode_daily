// 191. Number of 1 Bits

using namespace std;

#include <bits/stdc++.h>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n &= (n - 1);// drop the last 1 bit
            count++;
        }
        return count;
    }
};

class Solution2
{
public:
    int hammingWeight(uint32_t n)
    {
        return bitset<32>(n).count();
    }
};
