// 1508. Range Sum of Sorted Subarray Sums

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> sums;
        for (int i = 0; i < nums.size(); i++) {
            int local = 0;
            for (int j = i; j < nums.size(); j++) {
                local += nums[j];
                sums.push_back(local);
            }
        }

        sort(sums.begin(), sums.end());

        int res = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            res += sums[i];
            res %= 1000000007;
        }
        return res;
    }
};