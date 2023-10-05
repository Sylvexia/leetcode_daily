// 229. Majority Element II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        for (auto n : nums)
            u_map[n]++;

        int thresh = nums.size() / 3;
        vector<int> res;

        for (auto [key, count] : u_map)
            if (count > thresh)
                res.push_back(key);

        return res;
    }
};