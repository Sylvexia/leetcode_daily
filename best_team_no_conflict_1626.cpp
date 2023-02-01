// 1626. Best Team With No Conflicts

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dp[1001][1001];

    int dfs(vector<pair<int, int>> &data, int i, int prev_age)
    {
        if (i == data.size())
            return 0;

        if (dp[i][prev_age] != -1)
            return dp[i][prev_age];

        auto [score, age] = data[i];

        int res = dfs(data, i + 1, prev_age);

        if (age >= prev_age)
            res = max(res, score + dfs(data, i + 1, age));

        return dp[i][prev_age] = res;
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        memset(dp, -1, sizeof(dp));

        vector<pair<int, int>> data;

        for (int i = 0; i < scores.size(); i++)
            data.push_back({scores[i], ages[i]});

        sort(data.begin(), data.end());

        return dfs(data, 0, 0);
    }
};