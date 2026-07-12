// 3984. Divisible Game

#include <iostream>
#include <set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    long long maxScore(int k, vector<int> &nums)
    {
        long long current = 0;
        long long best = LLONG_MIN;

        for (int x : nums) {
            long long value = (x % k == 0) ? x : -x;
            current = max(value, current + value);
            best = max(best, current);
        }

        return best;
    }

public:
    int divisibleGame(vector<int> &nums)
    {
        constexpr int MOD = 1e9 + 7;
        set<int> candidates{2};

        for (int x : nums) {
            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d != 0)
                    continue;
                candidates.insert(d);
                candidates.insert(x / d);
            }
            if (x > 1)
                candidates.insert(x);
        }
        long long bestScore = LLONG_MIN;
        int bestK = 2;

        for (int k : candidates) {
            long long score = maxScore(k, nums);
            if (score > bestScore) {
                bestScore = score;
                bestK = k;
            }
        }
        return (bestScore % MOD + MOD) % MOD * bestK % MOD;
    }
};