// 75. Sort Colors

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        return sort(nums.begin(), nums.end());
    }
};

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, m = 0;

        while (m <= r)
        {
            switch (nums[m])
            {
            case 0:
                swap(nums[m++], nums[l++]);
                break;
            case 1:
                m++;
                break;
            case 2:
                swap(nums[m], nums[r--]);
                break;
            }
        }
        return;
    }
};