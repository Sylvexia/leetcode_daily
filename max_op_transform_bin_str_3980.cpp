// 3980. Minimum Operations to Transform Binary String

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionDP
{
public:
    int minOperations(string s1, string s2)
    {
        int n = s1.size();
        constexpr int INF = 1e9;

        auto cost = [&](int i, int t) -> int {
            char a = s1[i];
            char b = s2[i];

            if (t == 0) {
                if (a == '1' && b == '0')
                    return INF;
                return a != b;
            }

            return (a == '0') + (t - 1) + (b == '1');
        };

        vector<int> dp(2, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<int> ndp(2, INF);

            for (int prev = 0; prev <= 1; prev++) {
                for (int cur = 0; cur <= 1; cur++) {
                    if (dp[prev] == INF)
                        continue;
                    if (i == n - 1 && cur == 1)
                        continue;

                    int t = prev + cur;
                    int c = cost(i, t);

                    if (c == INF)
                        continue;

                    ndp[cur] = min(ndp[cur], dp[prev] + c + cur);
                }
            }

            dp = ndp;
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};

class Solution
{
public:
    int minOperations(string s1, string s2)
    {
        if (s1 == "1" and s2 == "0")
            return -1;
        int res = 0, n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            res++;
            if (s1[i] == '1') {
                if (i == n - 1) {
                    res++;
                } else {
                    res += s1[i + 1] == '0';
                    s1[i + 1] = '0';
                }
            }
        }
        return res;
    }
};