// 3795. Minimum Subarray Length With Distinct Sum At Least K

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> u_map;
        int sum = 0;
        int l{0}, r{0};
        int res = INT_MAX;
        for (; l < n; l++) {
            for (; r < n and sum < k; r++) {
                if (u_map[nums[r]] == 0)
                    sum += nums[r];
                u_map[nums[r]]++;
            }
            if (sum >= k)
                res = min(res, r - l);

            u_map[nums[l]]--;
            if (u_map[nums[l]] == 0) {
                sum -= nums[l];
                u_map.erase(nums[l]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};