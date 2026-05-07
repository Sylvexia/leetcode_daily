// 877. Stone Game

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionOn
{
    int dfs(int l,
            int r,
            bool isAlice,
            vector<int> &piles,
            vector<vector<int>> &dp)
    {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int left = isAlice ? piles[l] : -piles[l];
        int right = isAlice ? piles[r] : -piles[r];

        isAlice ^= 1;

        return dp[l][r] = max(dfs(l + 1, r, isAlice, piles, dp) + left,
                              dfs(l, r - 1, isAlice, piles, dp) + right);
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n - 1, true, piles, dp) > 0;
    }
};

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};