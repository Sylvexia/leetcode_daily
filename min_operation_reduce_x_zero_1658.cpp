// 1658. Minimum Operations to Reduce X to Zero

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (int n : nums)
            sum += n;

        int target = sum - x;
        int cur_sum = 0;
        int sub_size = -1;

        for (int l = 0, r = 0; r < nums.size(); r++) {
            cur_sum += nums[r];

            while (l <= r and cur_sum > target) {
                cur_sum -= nums[l];
                l++;
            }

            if (cur_sum == target)
                sub_size = max(sub_size, r - l + 1);
        }

        return sub_size == -1 ? -1 : nums.size() - sub_size;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,1,4,2,3};
    sol.minOperations(nums, 5);
    return 0;
}