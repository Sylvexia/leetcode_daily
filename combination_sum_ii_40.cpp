// 40. Combination Sum II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, vector<int> &gen, vector<vector<int>> &res, int start)
    {
        if (target == 0)
        {
            res.push_back(gen);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if(candidates[i]>target)
                return;
            if ((i > 0) && (candidates[i] == candidates[i - 1]) && (i > start))
                continue;
            gen.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], gen, res, i+1);
            gen.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> gen;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, gen, res, 0);
        return res;
    }
};