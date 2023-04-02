// 704. Binary Search

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
                return mid;

            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] >= target)
                r = m;

            else
                l = m + 1;
        }

        return (nums[l] == target) ? l : -1;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it == nums.end() ||
                       (*it != target)
                   ? -1
                   : it - nums.begin();
    }
};