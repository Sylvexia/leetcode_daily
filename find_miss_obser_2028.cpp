// 2028. Find Missing Observations

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int total = (rolls.size() + n) * mean;
        int target = total - accumulate(rolls.begin(), rolls.end(), 0);
        if (target > 6 * n || target < 1 * n)
            return {};
        int div = target / n;
        int mod = target % n;
        vector<int> res;
        for (int i = 0; i < mod; i++)
            res.push_back(div + 1);
        for (int i = 0; i < n - mod; i++)
            res.push_back(div);

        return res;
    }
};