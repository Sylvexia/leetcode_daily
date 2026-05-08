// 1406. Stone Game III

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<int> memo;
    int dfs(int i, vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        if (i == n)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int res = INT_MIN;
        int sum = 0;
        for (int take = 1; take <= 3 && i + take - 1 < n; take++) {
            sum += stoneValue[i + take - 1];
            res = max(res, sum - dfs(i + take, stoneValue));
        }
        return memo[i] = res;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        memo.resize(n, -1);
        int score = dfs(0, stoneValue);
        if (score > 0)
            return "Alice";
        else if (score < 0)
            return "Bob";
        return "Tie";
    }
};