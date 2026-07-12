// 3534. Path Existence Queries in a Graph II

#include <bit>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int up[18][100001];

    int cnt(int u, int v, int l)
    {
        if (u == v)
            return 0;
        if (up[0][u] >= v)
            return 1;
        if (up[l - 1][u] < v)
            return -1;

        int step = 0;
        for (int j = l - 1; j >= 0; j--) {
            if (up[j][u] < v) {
                step += (1 << j);
                u = up[j][u];
            }
        }
        return step + 1;
    }

public:
    vector<int> pathExistenceQueries(int n,
                                     vector<int> &nums,
                                     int maxDiff,
                                     vector<vector<int>> &queries)
    {
        int maxL = bit_width((unsigned) n) + 1;
        vector<pair<int, int>> getI(n);
        for (int i = 0; i < n; i++)
            getI[i] = {nums[i], i};
        ranges::sort(getI);

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[getI[i].second] = i;

        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n and getI[r + 1].first - getI[l].first <= maxDiff)
                r++;
            up[0][l] = r;
        }

        for (int j = 1; j < maxL; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];

        vector<int> res(queries.size());
        int i = 0;
        for (auto &q : queries) {
            auto [u, v] = minmax(pos[q[0]], pos[q[1]]);
            res[i++] = cnt(u, v, maxL);
        }
        return res;
    }
};