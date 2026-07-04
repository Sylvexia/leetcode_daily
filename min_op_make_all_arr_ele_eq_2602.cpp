// 2602. Minimum Operations to Make All Array Elements Equal

#include <algorithm>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        ranges::sort(nums);
        int n = nums.size();
        vector<long long> res, pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];
        for (int q : queries) {
            int i = ranges::lower_bound(nums, q) - nums.begin();
            res.push_back(1LL * (2 * i - n) * q + pre[n] - 2 * pre[i]);
        }
        return res;
    }
};