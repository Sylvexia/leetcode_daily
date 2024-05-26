// 552. Student Attendance Record II

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

static constexpr int mod = 1e9 + 7;

class Solution
{
    vector<vector<vector<int>>> cache;

    int dfs(int i, int a, int l, int n)
    {
        if (i == n)
            return 1;

        if (cache[i][a][l] != -1)
            return cache[i][a][l];

        long long int res = dfs(i + 1, a, 0, n);
        if (a == 0)
            res += dfs(i + 1, 1, 0, n);
        if (l < 2)
            res += dfs(i + 1, a, l + 1, n);

        return cache[i][a][l] = (int)(res % mod);
    }

public:
    int checkRecord(int n)
    {
        cache.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(0, 0, 0, n);
    }
};