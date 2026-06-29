// 3976. Maximum Subarray Sum After Multiplier
#include <climits>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    long long solve(vector<int> &nums, int k, bool isMul)
    {
        constexpr long long NEG = LLONG_MIN / 4;

        long long dp0 = NEG;
        long long dp1 = NEG;
        long long dp2 = NEG;
        long long res = NEG;

        for (int n : nums) {
            long long x = n;
            long long changed = isMul ? x * k : x / k;

            long long new_dp0 = max(x, dp0 + x);
            long long new_dp1 = max({changed, dp0 + changed, dp1 + changed});
            long long new_dp2 = max(dp1 + x, dp2 + x);

            dp0 = new_dp0;
            dp1 = new_dp1;
            dp2 = new_dp2;

            res = max({res, dp1, dp2});
        }
        return res;
    }

public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        return max(solve(nums, k, true), solve(nums, k, false));
    }
};