// 540. Single Element in a Sorted Array

#include <bits/stdc++.h>

using namespace std;

// 0112233
// 0123456
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int m = (l + r) / 2;

            if (m % 2 == 1)
                m--;

            if (nums[m] != nums[m + 1])
                r = m;
            else
                l = m + 2;
        }

        return nums[l];
    }
};