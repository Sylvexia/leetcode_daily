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