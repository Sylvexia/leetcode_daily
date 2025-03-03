// 2161. Partition Array According to Given Pivot

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> low, eq, high;

        for (int n : nums) {
            if (n < pivot)
                low.push_back(n);
            else if (n == pivot)
                eq.push_back(n);
            else
                high.push_back(n);
        }

        vector<int> res;
        for (int n : low)
            res.push_back(n);
        for (int n : eq)
            res.push_back(n);
        for (int n : high)
            res.push_back(n);

        return res;
    }
};