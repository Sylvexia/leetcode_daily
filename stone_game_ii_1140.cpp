// 1140. Stone Game II

#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<vector<int>>> dp;
    int dfs(int i, int m, bool is_alice, vector<int> &piles)
    {
        int n = piles.size();
        if (i >= n)
            return 0;
        if (dp[i][m][is_alice] != -1)
            return dp[i][m][is_alice];

        int res = 0;
        if (is_alice) {
            int taken = 0;
            res = 0;
            for (int p = 0; p + i < n and p < 2 * m; p++) {
                taken += piles[p + i];
                res = max(res,
                          dfs(p + i + 1, max(m, p + 1), false, piles) + taken);
            }
        } else {
            res = INT_MAX;
            for (int p = 0; p + i <= n and p < 2 * m; p++) {
                res = min(res, dfs(p + i + 1, max(m, p + 1), true, piles));
            }
        }
        return dp[i][m][is_alice] = res;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        dp.resize(piles.size() + 1,
                  vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        return dfs(0, 1, true, piles);
    }
};