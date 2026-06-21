// 1840. Maximum Building Height

#include <algorithm>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int pass(vector<vector<int>> &r)
    {
        int res = 0;
        for (int i = 0; i < r.size() - 1; ++i) {
            int h1 = r[i][1];
            int h2 = r[i + 1][1];
            int h = h1 + abs(r[i + 1][0] - r[i][0]);
            if (h > h2)
                h = h2 + (h - h2) / 2;
            res = max(res, h);
            r[i + 1][1] = min(h, h2);
        }
        return res;
    }

public:
    int maxBuilding(int n, vector<vector<int>> &r)
    {
        r.insert(r.end(), {{1, 0}, {n, n - 1}});
        ranges::sort(r);
        pass(r);
        ranges::reverse(r);
        return pass(r);
    }
};