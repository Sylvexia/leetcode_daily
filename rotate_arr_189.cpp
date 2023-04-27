// 189. Rotate Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int mod = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + mod);
        reverse(nums.begin() + mod, nums.end());
    }
};

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> copy = nums;
        for (int i = 0; i < nums.size(); i++)
            nums[(i + k) % nums.size()] = copy[i];
    }
};