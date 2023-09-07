// 80. Remove Duplicates from Sorted Array II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int n : nums) {
            if (i < 2 or n > nums[i - 2])
                nums[i++] = n;
        }
        return i;
    }
};