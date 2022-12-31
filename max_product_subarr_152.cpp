// 152. Maximum Product Subarray

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int p_max = 1, p_min = 1, ret = INT_MIN, n = nums.size();
        for (int n : nums)
        {
            if (n < 0)
                swap(p_max, p_min);

            p_max = max(n, n * p_max);
            p_min = min(n, n * p_min);

            ret = max(p_max, ret);
        }

        return ret;
    }
};