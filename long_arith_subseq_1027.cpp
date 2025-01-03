// 1027. Longest Arithmetic Subsequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int res = 2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diffMap = nums[j] - nums[i] + 500;
                dp[i][diffMap] = dp[j][diffMap] + 1;
                res = max(res, dp[i][diffMap]);
            }
        }
        return res;
    }
};