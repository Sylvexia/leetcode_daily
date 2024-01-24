// 918. Maximum Sum Circular Subarray

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int all = 0, max_sum = INT_MIN, min_sum = INT_MAX, cur_max = 0, cur_min = 0;

        for (int n : nums) {
            all += n;
            cur_max = max(cur_max + n, n);
            cur_min = min(cur_min + n, n);
            max_sum = max(max_sum, cur_max);
            min_sum = min(min_sum, cur_min);
        }

        return max_sum > 0 ? max(max_sum, all - min_sum) : max_sum;
    }
};