// 1493. Longest Subarray of 1's After Deleting One Element

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int res = 0;
        int zeros = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            zeros += (nums[r] == 0);
            while (zeros > 1) {
                zeros -= (nums[l] == 0);
                l++;
            }
            res = max(res, r - l + 1 - zeros);
        }
        return (res == nums.size()) ? res - 1 : res;
    }
};