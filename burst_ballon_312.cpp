// 312. Burst Balloons

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(int l, int r, vector<int> &nums)
    {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int res = 0;
        for (int i = l; i < r + 1; i++) {
            int cur = nums[l - 1] * nums[i] * nums[r + 1];
            cur += dfs(l, i - 1, nums) + dfs(i + 1, r, nums);
            res = max(res, cur);
        }
        return dp[l][r] = res;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(1, n - 2, nums);
    }
};