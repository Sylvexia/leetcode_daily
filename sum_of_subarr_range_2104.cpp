// 2104. Sum of Subarray Ranges

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxNum = nums[i];
            int minNum = nums[i];
            for (int j = i; j < n; j++) {
                maxNum = max(maxNum, nums[j]);
                minNum = min(minNum, nums[j]);
                res += (long long) maxNum - minNum;
            }
        }
        return res;
    }
};