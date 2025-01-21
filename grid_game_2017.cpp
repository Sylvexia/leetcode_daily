// 2017. Grid Game

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        vector<long long> top(n), bottom(n);

        for (int i = 1; i < n; i++) {
            top[n - 1 - i] = (long long) grid[0][n - i] + top[n - i];
            bottom[i] = (long long) grid[1][i - 1] + bottom[i - 1];
        }

        long long res = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            res = min(max(top[i], bottom[i]), res);
        }

        return res;
    }
};