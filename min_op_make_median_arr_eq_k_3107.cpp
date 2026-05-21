// 3107. Minimum Operations to Make Median of Array Equal to K

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mid = n / 2;
        ranges::sort(nums);
        long long res = abs(nums[mid] - k);
        nums[mid] = k;
        for (int i = mid; i - 1 >= 0; i--) {
            if (nums[i] < nums[i - 1]) {
                res += (long long) nums[i - 1] - nums[i];
                nums[i - 1] = nums[i];
            }
        }

        for (int i = mid; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) {
                res += (long long) nums[i] - nums[i + 1];
                nums[i + 1] = nums[i];
            }
        }
        return res;
    }
};