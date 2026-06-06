// 2574. Left and Right Sum Differences

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n), right(n), res(n);

        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i - 1];
            right[n - 1 - i] = right[n - i] + nums[n - i];
        }

        for (int i = 0; i < n; i++) {
            res[i] = abs(left[i] - right[i]);
        }

        return res;
    }
};