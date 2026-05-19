// 3334. Find the Maximum Factor Score of Array

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maxScore(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return 1LL * nums[0] * nums[0];

        vector<long long> pre_gcd(n), suf_gcd(n);
        vector<long long> pre_lcm(n), suf_lcm(n);

        pre_gcd[0] = nums[0];
        pre_lcm[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre_gcd[i] = gcd(pre_gcd[i - 1], (long long) nums[i]);
            pre_lcm[i] = lcm(pre_lcm[i - 1], (long long) nums[i]);
        }

        suf_gcd[n - 1] = nums[n - 1];
        suf_lcm[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf_gcd[i] = gcd(suf_gcd[i + 1], (long long) nums[i]);
            suf_lcm[i] = lcm(suf_lcm[i + 1], (long long) nums[i]);
        }

        long long res = pre_gcd[n - 1] * pre_lcm[n - 1];

        for (int i = 0; i < n; i++) {
            long long cur_gcd;
            long long cur_lcm;

            if (i == 0) {
                cur_gcd = suf_gcd[1];
                cur_lcm = suf_lcm[1];
            } else if (i == n - 1) {
                cur_gcd = pre_gcd[n - 2];
                cur_lcm = pre_lcm[n - 2];
            } else {
                cur_gcd = gcd(pre_gcd[i - 1], suf_gcd[i + 1]);
                cur_lcm = lcm(pre_lcm[i - 1], suf_lcm[i + 1]);
            }

            res = max(res, cur_gcd * cur_lcm);
        }

        return res;
    }
};