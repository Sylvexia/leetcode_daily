// 2731. Movement of Robots

#include <algorithm>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int sumDistance(vector<int> &nums, string s, int d)
    {
        constexpr long long MOD = 1e9 + 7;

        int n = nums.size();
        vector<long long> pos(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                pos[i] = (long long)nums[i] + d;
            else
                pos[i] = (long long)nums[i] - d;
        }

        ranges::sort(pos);

        long long res = 0;
        long long pref = 0;

        for (int i = 0; i < n; i++) {
            res = (res + i * pos[i] - pref) % MOD;
            pref = (pref + pos[i]) % MOD;
        }

        return (res + MOD) % MOD;
    }
};