// 190. Reverse Bits

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> bs{n};
        uint8_t l{0}, r{31};
        while (l < r)
        {
            bool temp = bs[r];
            bs[r] = bs[l];
            bs[l] = temp;
            l++, r--;
        }
        return bs.to_ulong();
    }
};

class Solution2
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

class Solution3
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        n = ((n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16);
        n = ((n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1);

        return n;
    }
};