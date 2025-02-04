// 1800. Maximum Ascending Subarray Sum

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int cur = nums[i];
            for (; j < n and nums[j - 1] < nums[j]; j++)
                cur += nums[j];
            res = max(res, cur);
        }
        return res;
    }
};