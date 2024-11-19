// 2461. Maximum Sum of Distinct Subarrays With Length K

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long res = 0, sum = 0;
        unordered_map<int, int> u_map;
        int i = 0, n = nums.size();
        while (i < k and i < n) {
            u_map[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if (u_map.size() == k)
            res = sum;
        for (; i < n; i++) {
            u_map[nums[i]]++;
            u_map[nums[i - k]]--;

            if (u_map[nums[i - k]] == 0)
                u_map.erase(nums[i - k]);

            sum += nums[i];
            sum -= nums[i - k];
            if (u_map.size() == k)
                res = max(res, sum);
        }
        return res;
    }
};