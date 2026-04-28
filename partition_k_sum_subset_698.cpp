// 698. Partition to K Equal Sum Subsets

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool backtrack(int i,
                   int k,
                   int curSum,
                   vector<bool> &used,
                   const int target,
                   const vector<int> &nums)
    {
        if (k == 0)
            return true;
        if (curSum == target)
            return backtrack(0, k - 1, 0, used, target, nums);

        for (int j = i; j < nums.size(); j++) {
            if (used[j])
                continue;
            if (curSum + nums[j] > target)
                continue;

            used[j] = true;
            if (backtrack(j + 1, k, curSum + nums[j], used, target, nums))
                return true;
            used[j] = false;

            if (curSum == 0)
                return false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), (int) 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;
        if (nums[0] > target)
            return false;
        sort(nums.rbegin(), nums.rend());
        vector<bool> used(nums.size(), false);
        return backtrack(0, k, 0, used, target, nums);
    }
};