// 945. Minimum Increment to Make Array Unique

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                continue;
            int offset = (nums[i - 1] - nums[i] + 1) ;
            res += offset;
            nums[i] += offset;
        }

        return res;
    }
};