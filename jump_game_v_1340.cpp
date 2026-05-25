// 1340. Jump Game V

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int i, vector<int> &arr, int d, vector<int> &dp)
    {
        if (dp[i] != -1)
            return dp[i];

        int res = 1;
        int n = arr.size();

        for (int cur = i + 1; cur <= min(i + d, n - 1); cur++) {
            if (arr[cur] >= arr[i])
                break;
            res = max(res, 1 + dfs(cur, arr, d, dp));
        }
        for (int cur = i - 1; cur >= max(i - d, 0); cur--) {
            if (arr[cur] >= arr[i])
                break;
            res = max(res, 1 + dfs(cur, arr, d, dp));
        }

        return dp[i] = res;
    }

public:
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        int res = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1)
                res = max(res, dfs(i, arr, d, dp));
        }
        return res;
    }
};