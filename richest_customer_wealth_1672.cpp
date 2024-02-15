// 1672. Richest Customer Wealth

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int res = 0;

        for (auto people : accounts) {
            int cur = accumulate(people.begin(), people.end(), 0);
            res = max(res, cur);
        }
        return res;
    }
};