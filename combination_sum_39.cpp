// 39. Combination Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, int start, vector<vector<int>> &res, vector<int> &r)
    {
        if (target == 0)
        {
            res.push_back(r);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++)
        {
            r.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, r);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> r;
        dfs(candidates, target, 0, res, r);
        return res;
    }
};