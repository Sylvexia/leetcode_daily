// 643. Maximum Average Subarray I

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int cur_sum = 0;

        for (int i = 0; i < k; i++)
            cur_sum += nums[i];

        int max_sum = cur_sum;

        for (int i = k; i < nums.size(); i++) {
            cur_sum -= nums[i - k];
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
        }

        return max_sum / double(k);
    }
};