// 1480. Running Sum of 1d Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> res{};
        int cum{};
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(cum + nums[i]);
            cum += nums[i];
        }
        return res;
    }
};