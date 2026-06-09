// 3689. Maximum Total Subarray Value I

#include <climits>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal = INT_MIN, minVal = INT_MAX;
        for(int n:nums)
        {
            maxVal = max(maxVal, n);
            minVal = min(minVal, n);
        }
        return (long long) k * (maxVal - minVal);
    }
};