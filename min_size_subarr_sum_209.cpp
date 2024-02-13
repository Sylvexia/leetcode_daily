// 209. Minimum Size Subarray Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int l = 0, cur = 0;
        int res = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            cur += nums[r];
            while (cur >= target) {
                res = min(res, r - l + 1);
                cur -= nums[l];
                l++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};