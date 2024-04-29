// 2997. Minimum Number of Operations to Make Array XOR Equal to K

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int xors = 0;
        for (int n : nums)
            xors ^= n;

        int res = 0;

        while (k or xors) {
            if ((k % 2) != (xors % 2))
                res++;
            k /= 2;
            xors /= 2;
        }

        return res;
    }
};