// 215. Kth Largest Element in an Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int quickselect(vector<int> &nums, int left, int right, int k)
    {
        int pivot{nums[right]}, p{left};

        for (int i{left}; i < right; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[p], nums[i]);
                p++;
            }
        }

        swap(nums[p], nums[right]);

        if (p > k)
            return quickselect(nums, left, p - 1, k);
        else if (p < k)
            return quickselect(nums, p + 1, right, k);
        else
            return nums[p];

        return nums[p];
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};