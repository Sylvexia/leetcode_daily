// 300. Longest Increasing Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = 0;
        for (auto cur : nums)
        {
            if (len == 0 || nums[len - 1] < cur)
                nums[len++] = cur;

            else
                *lower_bound(nums.begin(), nums.begin() + len, cur) = cur;
        }
        return len;
    }
};

class Solution2
{
public:
    array<int, 2501> dp{};
    int lengthOfLIS(vector<int> &nums)
    {
        for (auto &ele : dp)
            ele = 0;
    }
};