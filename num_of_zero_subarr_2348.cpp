// 2348. Number of Zero-Filled Subarrays

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline long long cal(long long x)
    {
        return (long long)(1 + x) * x / 2;
    }

public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long count = 0, res = 0;
        for (int x : nums)
        {
            if (x == 0)
                count++;
            else
            {
                res += cal(count);
                count = 0;
            }
        }
        res += cal(count);
        return res;
    }
};