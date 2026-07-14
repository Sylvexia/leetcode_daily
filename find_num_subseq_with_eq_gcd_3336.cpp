// 3336. Find the Number of Subsequences With Equal GCD

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int subsequencePairCount(vector<int> &nums)
    {
        constexpr int MOD = 1e9 + 7;
        int M = *ranges::max_element(nums);
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;

        for (int n : nums) {
            vector<vector<int>> dp2(M + 1, vector<int>(M + 1, 0));
            for (int i = 0; i <= M; i++) {
                for (int j = 0; j <= M; j++) {
                    int cur = dp[i][j];
                    int i2 = gcd(i, n);
                    int j2 = gcd(j, n);
                    dp2[i2][j] = (dp2[i2][j] + cur) % MOD;
                    dp2[i][j2] = (dp2[i][j2] + cur) % MOD;
                    dp2[i][j] = (dp2[i][j] + cur) % MOD;
                }
            }
            swap(dp, dp2);
        }

        int res = 0;
        for (int i = 1; i <= M; i++)
            res = (res + dp[i][i]) % MOD;
        return res;
    }
};