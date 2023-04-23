// 525. Contiguous Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> sum_idx{{0, -1}};
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum_idx.count(sum))
                res = max(res, i - sum_idx[sum]);
            else
                sum_idx[sum] = i;
        }

        return res;
    }
};