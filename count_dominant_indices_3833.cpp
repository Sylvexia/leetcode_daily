// 3833. Count Dominant Indices

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int dominantIndices(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            float avg = 0;
            for (int j = i + 1; j < n; j++)
                avg += nums[j];
            avg /= (float) (n - i - 1);
            res += nums[i] > avg;
        }
        return res;
    }
};