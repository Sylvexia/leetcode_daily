// 219. Contains Duplicate II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> pos{};
        for (int i = 0; i < nums.size(); i++)
        {
            if (pos.count(nums[i]))
            {
                int diff = i - pos[nums[i]];
                if (diff <= k)
                    return true;
            }
            pos[nums[i]] = i;
        }
        return false;
    }
};