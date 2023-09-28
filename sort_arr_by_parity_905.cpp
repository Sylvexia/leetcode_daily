// 905. Sort Array By Parity

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        for (int i = 0, even_p = 0; i < nums.size(); i++) {
            if (!(nums[i] & 1))
                swap(nums[i], nums[even_p++]);
        }

        return nums;
    }
};