// 491. Non-decreasing Subsequences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(vector<int> &nums, int depth, vector<int> &gen, vector<vector<int>> &res)
    {
        if (gen.size() > 1)
            res.push_back(gen);

        unordered_set<int> u_set{};

        for (int i = depth; i < nums.size(); i++)
        {
            if (!gen.empty() && (nums[i] < gen.back()) || u_set.find(nums[i]) != u_set.end())
                continue;
            gen.push_back(nums[i]);
            dfs(nums, i + 1, gen, res);
            gen.pop_back();
            u_set.insert(nums[i]);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> gen;
        vector<vector<int>> res;
        dfs(nums, 0, gen, res);
        return res;
    }
};