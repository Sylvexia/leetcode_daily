// 2366. Minimum Replacements to Sort the Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long num_frag = 1;
        long long right_val = 1e9;
        long long res = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            num_frag = (nums[i] + right_val - 1) / right_val;
            right_val = nums[i] / num_frag;
            res += num_frag - 1;
        }
        return res;
    }
};