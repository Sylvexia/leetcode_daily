// Maximum Score from Performing Multiplication Operations

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    array<array<int, 1000>, 1000> dp;

    int dfs(vector<int> &nums, vector<int> &multipliers, int i, int left, int right)
    {
        if (i == multipliers.size())
            return 0;

        if (dp[left][i] != INT_MIN)
            return dp[left][i];

        int first = multipliers[i] * nums[left] + dfs(nums, multipliers, i + 1, left + 1, right);
        int last = multipliers[i] * nums[right] + dfs(nums, multipliers, i + 1, left, right - 1);

        dp[left][i] = max(first, last);

        return dp[left][i];
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        for (auto &row : dp)
        {
            for (auto &col : row)
            {
                col = INT_MIN;
            }
        }

        return dfs(nums, multipliers, 0, 0, nums.size()-1);
    }
};