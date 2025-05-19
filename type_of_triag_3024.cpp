// 3024. Type of Triangle

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> u_map;
        for (int n : nums)
            u_map[n]++;

        if (nums[0] + nums[1] <= nums[2])
            return "none";

        if (u_map.size() == 1)
            return "equilateral";
        if (u_map.size() == 2)
            return "isosceles";
        if (u_map.size() == 3)
            return "scalene";
        return "none";
    }
};