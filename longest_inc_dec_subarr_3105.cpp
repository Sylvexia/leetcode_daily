// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int inc = 1, dec = 1;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            for (; j < n and nums[j - 1] < nums[j]; j++) {
            }
            inc = max(inc, j - i);
            i = j - 1;
        }

        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            for (; j < n and nums[j - 1] > nums[j]; j++) {
            }
            dec = max(dec, j - i);
            i = j - 1;
        }

        return max(inc, dec);
    }
};