// 216. Combination Sum III

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(int k, int n, int start, vector<int> &gen, vector<vector<int>> &res)
    {
        if (n == 0 && k == 0)
        {
            res.push_back(gen);
            return;
        }
        if (n < 0 || k < 0)
        {
            return;
        }

        for (int i = start; i < 10; i++)
        {
            gen.push_back(i);
            dfs(k - 1, n - i, i + 1, gen, res);
            gen.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> gen;
        dfs(k, n, 1, gen, res);
        return res;
    }
};