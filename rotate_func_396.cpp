// 396. Rotate Function

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i] * i;
        }

        int sum = accumulate(nums.begin(), nums.end(), (int) 0);

        int res = temp;
        for (int i = 0; i < n - 1; i++) {
            temp = temp + sum - nums[n - 1 - i] * (n);
            res = max(temp, res);
        }
        return res;
    }
};