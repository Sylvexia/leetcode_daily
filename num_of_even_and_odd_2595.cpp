// 2595. Number of Even and Odd Bits

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        int even = 0, odd = 0;
        bool isodd = false;
        while (n != 0)
        {
            if (n & 1)
            {
                if (isodd)
                    odd++;
                else
                    even++;
            }
            isodd = not isodd;
            n /= 2;
        }
        return {even, odd};
    }
};