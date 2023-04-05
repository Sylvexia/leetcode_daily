// 2439. Minimize Maximum of Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline bool is_val(vector<int> &nums, int m)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > (long long)m * (i + 1))
                return false;
        }

        return true;
    }

public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (is_val(nums, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};