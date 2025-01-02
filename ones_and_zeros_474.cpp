// 474. Ones and Zeroes

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    typedef pair<int, int> pii;
    vector<vector<vector<int>>> dp;
    int dfs(int i,
            int m,
            int n,
            vector<string> &strs,
            unordered_map<int, pii> &u_map)
    {
        if (m < 0 or n < 0)
            return INT_MIN;
        if (i >= strs.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int take = 1 + dfs(i + 1, m - u_map[i].first, n - u_map[i].second, strs,
                           u_map);
        int notTake = dfs(i + 1, m, n, strs, u_map);
        return dp[i][m][n] = max(take, notTake);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        dp.resize(strs.size(),
                  vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        unordered_map<int, pii> u_map;
        for (int i = 0; i < strs.size(); i++) {
            int cur0 = 0, cur1 = 0;
            string cur = strs[i];
            for (char ch : cur)
                cur0 += (ch == '0'), cur1 += (ch == '1');
            u_map[i] = {cur0, cur1};
        }
        return dfs(0, m, n, strs, u_map);
    }
};