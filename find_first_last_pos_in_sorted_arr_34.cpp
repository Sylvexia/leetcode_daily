// 34. Find First and Last Position of Element in Sorted Array

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int idx1 = lower_bound_c(nums, target);
        int idx2 = lower_bound_c(nums, target + 1) - 1;

        if (idx2 < idx1)
            return {-1, -1};
        else
            return {idx1, idx2};
    }

    int lower_bound_c(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};