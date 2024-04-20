// 1992. Find All Groups of Farmland

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> res;

        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (!land[i][j])
                    continue;

                int c = j;
                while (c < land[0].size() and land[i][c])
                    c++;

                int r = i;
                while (r < land.size() and land[r][j])
                    r++;

                c = c == 0 ? c : c - 1;
                r = r == 0 ? r : r - 1;

                res.push_back({i, j, r, c});

                for (int k = i; k <= r; k++) {
                    for (int l = j; l <= c; l++)
                        land[k][l] = 0;
                }
            }
        }

        return res;
    }
};