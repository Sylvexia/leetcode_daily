// 2958. Length of Longest Subarray With at Most K Frequency

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int res = 0;
        int r = 0, l = 0;
        unordered_map<int, int> cnt;
        for (; r < nums.size(); r++) {
            cnt[nums[r]]++;
            if (cnt[nums[r]] > k) {
                while (nums[l] != nums[r]) {
                    cnt[nums[l]]--;
                    l++;
                }
                cnt[nums[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};