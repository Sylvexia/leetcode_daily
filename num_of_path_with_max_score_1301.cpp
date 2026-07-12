// 1301. Number of Paths with Max Score

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    static constexpr int MOD = 1e9 + 7;

public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int n = board.size();
        using pii = pair<int, int>;
        vector<vector<pii>> dp(n, vector<pii>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};

        auto update = [&](int x, int y, int u, int v) {
            if (u >= n or v >= n)
                return;
            if (dp[u][v].first == -1)
                return;
            if (dp[u][v].first > dp[x][y].first)
                dp[x][y] = dp[u][v];
            else if (dp[u][v].first == dp[x][y].first) {
                dp[x][y].second += dp[u][v].second;
                dp[x][y].second %= MOD;
            }
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1 and j == n - 1)
                    continue;
                if (board[i][j] == 'X')
                    continue;
                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);
                if (dp[i][j].first != -1)
                    dp[i][j].first +=
                        (board[i][j] == 'E' ? 0 : board[i][j] - '0');
            }
        }

        return dp[0][0].first == -1
                   ? vector<int>{0, 0}
                   : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};