// 2419. Longest Subarray With Maximum Bitwise AND

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max_num = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != max_num)
                continue;
            int window = 0;
            int j;
            for (j = i; j < nums.size() and nums[j] == max_num; j++) {
                window++;
            }
            i = j - 1;
            res = max(res, window);
        }
        return res;
    }
};