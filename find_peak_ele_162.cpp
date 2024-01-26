// 162. Find Peak Element

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int l = 0, r = nums.size() - 1;
        if (nums[l] > nums[l + 1])
            return l;
        if (nums[r] > nums[r - 1])
            return r;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (m - 1 > 0 and nums[m] < nums[m - 1])
                r = m - 1;
            else if (m + 1 < nums.size() and nums[m] < nums[m + 1])
                l = m + 1;
            else
                return m;
        }
        return l;
    }
};