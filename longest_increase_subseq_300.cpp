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

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int res = 1;
        int dp[nums.size()];
        for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++)
            dp[i] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};