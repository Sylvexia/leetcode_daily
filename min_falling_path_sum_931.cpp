// 931. Minimum Falling Path Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<pair<int, int>> dirs{{1, -1}, {1, 0}, {1, 1}};

    int dfs(vector<vector<int>> &matrix, const int i, const int j, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= matrix[0].size())
            return INT_MAX;

        if (i == matrix.size() - 1 && j >= 0 && j <= matrix[0].size())
            return matrix[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int future = INT_MAX;

        for (auto [row, col] : dirs)
            future = min(future, dfs(matrix, i + row, j + col, dp));

        dp[i][j] = matrix[i][j] + future;

        return dp[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int res = INT_MAX, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            res = min(res, dfs(matrix, 0, i, dp));

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << sol.minFallingPathSum(data);
}