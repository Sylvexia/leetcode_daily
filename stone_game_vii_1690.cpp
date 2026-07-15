// 1690. Stone Game VII

#include <iostream>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(int i, int j, int total, vector<int> &stones)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int l = - dfs(i + 1, j, total - stones[i], stones) + total - stones[i];
        int r = - dfs(i, j - 1, total - stones[j], stones) + total - stones[j];
        return dp[i][j] = max(l, r);
    }

public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(0, n - 1, accumulate(stones.begin(), stones.end(), (int) 0),
                   stones);
    }
};