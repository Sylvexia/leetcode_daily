// 46. Permutations

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &nums, int start, vector<vector<int>> &res)
    {
        if (start == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
};