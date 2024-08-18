// 1937. Maximum Number of Points with Cost

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution_TLE
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = points[0][i];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - 1][k] + points[i][j] - abs(j - k));
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, (long long) dp[m - 1][i]);

        return res;
    }  // TLE
};

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = points[0][i];

        for (int i = 1; i < m; i++) {
            vector<long long> left_dp(points[i].size(), -1);
            vector<long long> right_dp(points[i].size(), -1);

            left_dp[0] = dp[i - 1][0];
            for (int k = 1; k < n; k++) {
                left_dp[k] = max(left_dp[k - 1], dp[i - 1][k] + k);
            }

            right_dp.back() = dp[i - 1].back() - n + 1;
            for (int k = n - 2; k >= 0; k--) {
                right_dp[k] = max(right_dp[k + 1], dp[i - 1][k] - k);
            }

            for (int j = 0; j < points[i].size(); j++)
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, (long long) dp[m - 1][i]);

        return res;
    }
};