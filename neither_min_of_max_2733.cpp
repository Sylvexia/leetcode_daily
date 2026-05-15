// 2733. Neither Minimum nor Maximum

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return -1;

        sort(nums.begin(), nums.end());
        return nums[1];
    }
};