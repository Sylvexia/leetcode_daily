// 238. Product of Array Except Self

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(), begin = 1, end = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= begin;
            begin *= nums[i];

            res[n - i - 1] *= end;
            end *= nums[n - i - 1];
        }
        return res;
    }
};