// 3701. Compute Alternating Sum

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int alternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i += 2)
            res += nums[i];
        for (int i = 1; i < n; i += 2)
            res -= nums[i];
        return res;
    }
};