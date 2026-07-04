// 3979. Maximum Valid Pair Sum

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int l = nums[0];
        int res = INT_MIN;

        for(int j = k;j<n;j++)
        {
            l = max(l, nums[j - k]);
            res = max(res, l + nums[j]);
        }

        return res;
    }
};