// 992. Subarrays with K Different Integers

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int atMostK(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int res = 0;
        unordered_map<int, int> cnt;
        while (r < nums.size()) {
            cnt[nums[r]]++;
            while (cnt.size() > k) {
                cnt[nums[l]]--;
                if (cnt[nums[l]] == 0)
                    cnt.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};