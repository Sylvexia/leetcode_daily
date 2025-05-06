// 1920. Build Array from Permutation

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};