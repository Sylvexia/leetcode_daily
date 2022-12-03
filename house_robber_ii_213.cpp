// 213. House Robber II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob_helper(vector<int> &nums, int start, int end)
    {
        int prev_1 = 0, prev_2 = 0, cur = 0;
        for (int i = start; i < end; i++)
        {
            cur = max(prev_2 + nums[i], prev_1);
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return cur;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return max(nums[0] + rob_helper(nums, 2, n - 1), rob_helper(nums, 1, n));
    }
};