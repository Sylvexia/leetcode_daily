// 2401. Longest Nice Subarray

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int cur = 0;
        int res = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            for (; (cur & nums[r]) != 0; l++)
                cur ^= nums[l];
            cur |= nums[r];
            res = max(res, r - l + 1);
        }
        return res;
    }
};