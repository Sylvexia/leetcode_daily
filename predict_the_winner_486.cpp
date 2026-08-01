// 486. Predict the Winner

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<int> &nums)
    {
        if (i == j)
            return nums[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = nums[i] - dfs(i + 1, j, nums);
        int right = nums[j] - dfs(i, j - 1, nums);
        return max(left, right);
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(0, n - 1, nums) >= 0;
    }
};