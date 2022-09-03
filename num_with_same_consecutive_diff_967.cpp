// 967. Numbers With Same Consecutive Differences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(int num, int n, int k, vector<int> &res)
    {
        if (n == 0)
        {
            res.push_back(num);
            return;
        }

        int dig = num % 10;

        if (dig + k <= 9)
            dfs(num * 10 + dig + k, n - 1, k, res);
        if (dig >= k)
            dfs(num * 10 + dig - k, n - 1, k, res);

        return;
    }

    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        for (int num = 1; num <= 9; ++num)
        {
            dfs(num, n - 1, k, res);
        }
        return res;
    }
};