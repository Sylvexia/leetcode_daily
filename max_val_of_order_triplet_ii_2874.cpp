// 2874. Maximum Value of an Ordered Triplet II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        vector<int> maxDiff;
        int n = nums.size();
        int curMax = nums[0];
        int curRes = INT_MIN;
        for (int i = 1; i < n; i++) {
            curRes = max(curRes, curMax - nums[i]);
            maxDiff.push_back(curRes);
            curMax = max(curMax, nums[i]);
        }
        long long res = 0;
        for (int i = 2; i < n; i++) {
            res = max(res, (long long) nums[i] * maxDiff[i - 2]);
        }
        return res;
    }
};