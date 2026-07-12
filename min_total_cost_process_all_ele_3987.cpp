// 3987. Minimum Total Cost to Process All Elements

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumCost(vector<int> &nums, int k)
    {
        constexpr int MOD = 1e9 + 7;
        long long res = 0;
        long long cost = 1;
        long long cur = k;
        int n = nums.size();
        for (long long x : nums) {
            if (cur < x) {
                long long cnt = (x - cur + k - 1) / k;

                __int128 addedCost =
                    (__int128)cnt * (2 * (__int128)cost + cnt - 1) / 2;

                res = (res + addedCost % MOD) % MOD;

                cur += cnt * k;
                cost += cnt;
            }

            cur -= x;
        }
        return res % (MOD);
    }
};