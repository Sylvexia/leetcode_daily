// 1267. Count Servers that Communicate

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += grid[i][j] != 0;
            }
            if (cnt < 2)
                continue;
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0)
                    grid[i][j] = 2;
        }

        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                cnt += grid[i][j] != 0;
            }
            if (cnt < 2)
                continue;
            for (int i = 0; i < m; i++)
                if (grid[i][j] != 0)
                    grid[i][j] = 2;
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                res += grid[i][j] == 2;
        }
        return res;
    }
};