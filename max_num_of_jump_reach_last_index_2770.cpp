// 2770. Maximum Number of Jumps to Reach the Last Index

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        memo[0] = 0;
        for (int i = 1; i < n; i++) {
            int cur = -1;
            for (int j = 0; j < i; j++) {
                if (target >= abs(nums[i] - nums[j]))
                    cur = max(cur, memo[j]);
            }
            if (cur != -1)
                memo[i] = cur + 1;
        }
        return memo[n - 1];
    }
};