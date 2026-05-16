// 3350. Adjacent Increasing Subarrays Detection II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 1;
        int precnt = 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                cnt++;
            else {
                precnt = cnt;
                cnt = 1;
            }
            res = max(res, min(precnt, cnt));
            res = max(res, cnt / 2);
        }
        return res;
    }
};