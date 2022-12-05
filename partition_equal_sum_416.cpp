// 416. Partition Equal Subset Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &ele : nums)
            sum += ele;

        if (sum & 1)
            return false;

        int half = sum / 2;

        bool dp[half + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int num : nums)
        {
            for (int j = half; j >= num; j--)
            {
                if (dp[j - num])
                    dp[j] = true;
            }
        }

        return dp[half];
    }
};

class Solution2
{
public:
    int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};
    bool dfs(vector<int> &nums, int target, int i)
    {
        if (target == 0)
            return true;
        if (i >= nums.size() || target < 0)
            return false;
        if (dp[i][target] != -1)
            return dp[i][target];
        return dp[i][target] = dfs(nums, target - nums[i], i + 1) ||
                               dfs(nums, target, i + 1);
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &ele : nums)
            sum += ele;

        if (sum & 1)
            return false;

        sort(nums.rbegin(), nums.rend());

        return dfs(nums, sum / 2, 0);
    }
};