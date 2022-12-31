// 53. Maximum Subarray

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int s_max = INT_MIN, sum = 0;

        for (auto num : nums)
        {
            sum += num;
            s_max = max(s_max, sum);
            if (sum < 0)
                sum = 0;
        }

        return s_max;
    }
};