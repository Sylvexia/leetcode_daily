#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> dp;
    int dfs(int i, int target, vector<int> &nums)
    {
        if (target == 0)
            return 0;
        if (target < 0)
            return INT_MIN;
        if (i >= nums.size())
            return INT_MIN;
        if (dp[i][target] != -1)
            return dp[i][target];

        int take = dfs(i + 1, target - nums[i], nums) + 1;
        int not_take = dfs(i + 1, target, nums);
        return dp[i][target] = max(take, not_take);
    }

public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        dp.resize(nums.size(), vector<int>(target + 1, -1));
        int res = dfs(0, target, nums);
        return res > 0 ? res : -1;
    }
};