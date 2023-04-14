// 283. Move Zeroes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = nums.size() - 1;

        while (i >= 0)
        {
            while (i >= 0 and nums[i] != 0)
                i--;

            if (i < 0)
                return;

            int j = i + 1;
            while (j < nums.size() and nums[j] != 0)
            {
                swap(nums[j], nums[j - 1]);
                j++;
            }

            i--;
        }

        return;
    }
};