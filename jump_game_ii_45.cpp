// 45. Jump Game II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    const int max = 10001;

public:
    int dfs(vector<int> &dp, vector<int> &nums, int pos)
    {
        if (pos > nums.size())
            return 0;

        if (dp[pos] != max)
            return dp[pos];

        for (int j = 1; j <= nums[pos]; j++)
            dp[pos] = min(dp[pos], 1 + dfs(dp, nums, pos + j));

        return dp[pos];
    }

    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), max);

        return dfs(dp, nums, 0);
    }
};