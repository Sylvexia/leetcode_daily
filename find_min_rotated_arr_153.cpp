// 153. Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l{0}, r = nums.size() - 1;

        while (l < r)
        {
            int m{l + (r - l) / 2};
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m + 1;
        }
        return nums[l];
    }
};