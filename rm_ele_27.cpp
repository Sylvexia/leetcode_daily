// 27. Remove Element

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int res = nums.size();

        for (auto ele : nums) {
            res -= (ele == val);
        }


        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j<nums.size() and nums[i] == val) {
                swap(nums[i], nums[j]);
                j++;
            }
            if (j >= nums.size())
                return res;
        }

        return res;
    }
};