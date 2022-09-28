// 1. Two Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp{}; // mp[answer]=traversed index
        vector<int> res{};

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                return {i, mp[nums[i]]};
            }
            mp[target - nums[i]] = i;
        }

        return {-1, -1};
    }
};