// 2302. Count Subarrays With Score Less Than K

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long curSum = 0;
        int l = 0, r = 0;
        int n = nums.size();
        long long res = 0;

        for (; r < n; r++) {
            curSum += nums[r];
            for (; (curSum * (r - l + 1)) >= k; l++) {
                curSum -= nums[l];
            }
            res += r - l + 1;
        }
        return res;
    }
};