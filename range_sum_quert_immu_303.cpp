// 303. Range Sum Query - Immutable

#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> prefix;
    NumArray(vector<int> &nums)
    {
        prefix = vector<int>(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i];
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefix[right];
        else
            return prefix[right] - prefix[left - 1];
    }
};