// 1749. Maximum Absolute Sum of Any Subarray

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int res_max = 0, res_min = 0;
        int cur_max = 0, cur_min = 0;

        for (int n : nums) {
            cur_max = max(cur_max + n, n);
            res_max = max(res_max, cur_max);

            cur_min = min(cur_min + n, n);
            res_min = min(res_min, cur_min);
        }

        return max(res_max, abs(res_min));
    }
};