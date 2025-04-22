// 2338. Count the Number of Ideal Arrays
// I can't

#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    int memo[10001][15];
    long long comb(int n, int k)
    {
        if (k == 0)
            return 1;
        if (n == k)
            return 1;
        if (memo[n][k] != -1)
            return memo[n][k];
        return memo[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod;
    }

public:
    int idealArrays(int n, int maxValue)
    {
        vector<vector<int>> dp(15, vector<int>(maxValue + 1));
        fill(dp[1].begin(), dp[1].end(), 1);
        dp[1][0] = 0;

        unordered_map<int, vector<int>> divs;
        for (int i = 1; i <= maxValue; i++) {
            for (int j = i * 2; j <= maxValue; j += i) {
                divs[i].push_back(j);
            }
        }

        for (int i = 2; i <= min(n, 14); i++) {
            for (int j = 1; j <= maxValue; j++) {
                for (int div : divs[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][div]) % mod;
                }
            }
        }

        long res = 0;
        memset(memo, -1, sizeof(memo));

        for (int i = 1; i <= min(n, 14); i++) {
            long counts = 0;
            for (int j = 1; j <= maxValue; j++) {
                counts = (counts + dp[i][j] % mod);
            }
            res = (res + (counts * comb(n - 1, i - 1)) % mod) % mod;
        }
        return res;
    }
};