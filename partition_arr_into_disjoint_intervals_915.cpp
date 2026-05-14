// 915. Partition Array into Disjoint Intervals

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> rightMin(n), leftMax(n);

        leftMax[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMin[i] = min(rightMin[i + 1], nums[i]);

        for (int i = 0; i < n - 1; i++) {
            if (leftMax[i] <= rightMin[i + 1])
                return i + 1;
        }
        return n;
    }
};