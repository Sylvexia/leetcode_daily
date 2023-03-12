// 494. Target Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(int i, vector<int> &nums, int target,
            vector<unordered_map<int, int>> &mem)
    {
        if (i == nums.size())
            return (target == 0);

        if (mem[i].find(target) != mem[i].end())
            return mem[i][target];

        int pos = dfs(i + 1, nums, target - nums[i], mem);
        int neg = dfs(i + 1, nums, target + nums[i], mem);

        return mem[i][target] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<unordered_map<int, int>> mem(nums.size());
        return dfs(0, nums, target, mem);
    }
};