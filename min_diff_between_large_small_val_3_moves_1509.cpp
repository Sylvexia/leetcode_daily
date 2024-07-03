// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 5)
            return 0;
        sort(nums.begin(), nums.end());
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2],
                    nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};