// 1590. Make Sum Divisible by P

#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long long int sum =
            accumulate(nums.begin(), nums.end(), (long long int) 0);
        int remain = sum % p;

        if (remain == 0)
            return 0;

        int cur_sum = 0;
        int res = n;
        unordered_map<int, int> u_map{{0, -1}};
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            cur_sum %= p;
            int target = (cur_sum - remain + p) % p;

            if (u_map.find(target) != u_map.end())
                res = min(res, i - u_map[target]);
            u_map[cur_sum] = i;
        }
        return res == n ? -1 : res;
    }
};