// 1395. Count Number of Teams

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int res = 0;
        vector<vector<int>> inc_mem(n, vector<int>(4, -1));
        vector<vector<int>> dec_mem(n, vector<int>(4, -1));

        for (int i = 0; i < n; i++) {
            res += dfs(rating, i, 1, inc_mem, true);
            res += dfs(rating, i, 1, dec_mem, false);
        }
        return res;
    }

    int dfs(vector<int> &rating,
            int i,
            int team_size,
            vector<vector<int>> &dp,
            bool is_inc)
    {
        if (i == rating.size())
            return 0;

        if (team_size == 3)
            return 1;

        if (dp[i][team_size] != -1)
            return dp[i][team_size];

        int res = 0;

        for (int j = i + 1; j < rating.size(); j++) {
            bool condition =
                (is_inc) ? rating[j] > rating[i] : rating[j] < rating[i];
            if (condition)
                res += dfs(rating, j, team_size + 1, dp, is_inc);
        }

        return dp[i][team_size] = res;
    }
};