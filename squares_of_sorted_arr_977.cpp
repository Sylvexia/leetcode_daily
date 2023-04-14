// 977. Squares of a Sorted Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int &n : nums)
            n = n * n;
        sort(nums.begin(), nums.end());

        return nums;
    }
};

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (abs(nums[r]) > abs(nums[l]))
                res[i] = nums[r] * nums[r], r--;
            else
                res[i] = nums[l] * nums[l], l++;
        }
        return res;
    }
};