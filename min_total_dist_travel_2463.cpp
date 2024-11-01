// 2463. Minimum Total Distance Traveled

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<long long>> dp;
    long long dfs(int i, int j, vector<int> &robot, vector<int> &factory)
    {
        if (i == robot.size())
            return 0;
        if (j == factory.size())
            return LONG_LONG_MAX - INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long take =
            dfs(i + 1, j + 1, robot, factory) + abs(robot[i] - factory[j]);
        long long not_take = dfs(i, j + 1, robot, factory);
        return dp[i][j] = min(take, not_take);
    }

public:
    long long minimumTotalDistance(vector<int> &robot,
                                   vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> fac_pos;
        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++)
                fac_pos.push_back(f[0]);
        }
        dp.resize(robot.size() + 1, vector<long long>(fac_pos.size() + 1, -1));
        return dfs(0, 0, robot, fac_pos);
    }
};