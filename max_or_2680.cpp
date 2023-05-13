// 2680. Maximum OR

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumOr(vector<int> &nums, int k)
    {
        int n = nums.size();
        int pre[n + 1], suf[n + 1];
        pre[0] = 0;
        suf[n] = 0;

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] | nums[i];

        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] | nums[i];

        long long p = 1;
        p <<= k;
        long long res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, (pre[i] | (nums[i] * p) | suf[i + 1]));

        return res;
    }
};