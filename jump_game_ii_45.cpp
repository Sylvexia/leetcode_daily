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

class Solution2
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size(), max_pos = 0, cur_pos = 0, last_pos = 0, res = 0;

        while (last_pos < n - 1)
        {
            max_pos = max(max_pos, cur_pos + nums[cur_pos]);

            if (cur_pos == last_pos)
            {
                last_pos = max_pos;
                res++;
            }
            cur_pos++;
        }

        return res;
    }
};