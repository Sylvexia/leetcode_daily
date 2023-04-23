// 90. Subsets II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &nums, const int n, vector<int> &gen, vector<vector<int>> &res, bool choosePre)
    {
        if (n == nums.size())
        {
            res.push_back(gen);
            return;
        }
        dfs(nums, n + 1, gen, res, false);

        if (n > 0 && nums[n] == nums[n - 1] && !choosePre)
            return;

        gen.push_back(nums[n]);
        dfs(nums, n + 1, gen, res, true);
        gen.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> gen;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, gen, res, false);
        return res;
    }
};