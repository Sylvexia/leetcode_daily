// 78. Subsets

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void generator(const vector<int> &nums, const int n, vector<int> &gen, vector<vector<int>> &res)
    {
        if (n == nums.size())
        {
            res.push_back(gen);
            return;
        }

        generator(nums, n + 1, gen, res);
        gen.push_back(nums[n]);
        generator(nums, n + 1, gen, res);
        gen.pop_back();

    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> gen;
        vector<vector<int>> res;
        generator(nums, 0, gen, res);
        return res;
    }
};