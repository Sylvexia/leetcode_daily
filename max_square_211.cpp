// 221. Maximal Square

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[301][301];
    int max_side = 0;
    int dfs(int i, int j, vector<vector<char>> &m)
    {
        if (i >= m.size() or j >= m[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 0;
        int diag = dfs(i + 1, j + 1, m);
        int right = dfs(i, j + 1, m);
        int bottom = dfs(i + 1, j, m);
        
        if (m[i][j] == '1')
            res = 1 + min({diag, right, bottom});

        max_side = max(res, max_side);

        return dp[i][j] = res;
    }

public:
    int maximalSquare(vector<vector<char>> &m)
    {
        memset(dp, -1, sizeof(dp));
        dfs(0, 0, m);
        return max_side * max_side;
    }
};