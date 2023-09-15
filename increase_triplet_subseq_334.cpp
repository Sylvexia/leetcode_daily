// 334. Increasing Triplet Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min_1 = INT_MAX, min_2 = INT_MAX;

        for (int n : nums) {
            if (n <= min_1)
                min_1 = n;
            else if (n <= min_2)
                min_2 = n;
            else
                return true;
        }

        return false;
    }
};

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left_min(n), right_max(n);

        left_min[0] = nums[0];
        right_max[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            left_min[i] = min(nums[i], left_min[i - 1]);
        }

        for (int i = n - 1; i > 0; i--) {
            right_max[i - 1] = max(nums[i - 1], right_max[i]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > left_min[i] and nums[i] < right_max[i])
                return true;
        }

        return false;
    }
};