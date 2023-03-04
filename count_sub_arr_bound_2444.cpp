// 2444. Count Subarrays With Fixed Bounds

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ret = 0;
        int min_pos = -1, max_pos = -1, left_bound = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= minK and nums[i] <= maxK)
            {
                min_pos = (nums[i] == minK) ? i : min_pos;
                max_pos = (nums[i] == maxK) ? i : max_pos;
                ret += max(0, min(max_pos, min_pos) - left_bound);
            }
            else
            {
                left_bound = i;
                max_pos = -1, min_pos = -1;
            }
        }

        return ret;
    }
};