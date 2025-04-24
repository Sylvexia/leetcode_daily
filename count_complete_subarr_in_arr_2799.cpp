// 2799. Count Complete Subarrays in an Array

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int total = unordered_set<int>(nums.begin(), nums.end()).size();

        unordered_map<int, int> uMap;

        int l = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            uMap[nums[r]]++;
            for (; uMap.size() == total; l++) {
                res += nums.size() - r;
                uMap[nums[l]]--;
                if (uMap[nums[l]] == 0)
                    uMap.erase(nums[l]);
            }
        }
        return res;
    }
};