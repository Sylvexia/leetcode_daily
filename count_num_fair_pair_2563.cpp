// 2563. Count the Number of Fair Pairs

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    long long cal(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        long long res = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target) {
                res += r - l;
                l++;
            } else
                r--;
        }
        return res;
    }

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return cal(nums, upper + 1) - cal(nums, lower);
    }
};