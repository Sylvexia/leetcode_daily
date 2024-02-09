// 368. Largest Divisible Subset

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<int, vector<int>> dp;
    vector<int> dfs(vector<int> &nums, int start)
    {
        if (start >= nums.size())
            return {};
        if (dp.count(start))
            return dp[start];
        for (int j = start + 1; j < nums.size(); j++) {
            if (nums[j] % nums[start])
                continue;
            auto tmp = dfs(nums, j);
            if (tmp.size() >= dp[start].size())
                dp[start] = tmp;
        }
        dp[start].push_back(nums[start]);
        return dp[start];
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto tmp = dfs(nums, i);
            if (tmp.size() > res.size())
                res = tmp;
        }
        return res;
    }
};