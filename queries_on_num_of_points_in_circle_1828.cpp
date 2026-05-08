// 1828. Queries on Number of Points Inside a Circle

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionOn
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        vector<int> res;
        for (auto &q : queries) {
            int cur = 0;
            for (auto &p : points) {
                int a = p[0] - q[0];
                int b = p[1] - q[1];
                cur += (q[2] * q[2] >= a * a + b * b);
            }
            res.push_back(cur);
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        vector<int> res;
        vector<array<int, 2>> sp;
        for (auto &p : points)
            sp.push_back({p[0], p[1]});
        sort(begin(sp), end(sp));

        for (auto &q : queries) {
            int cnt = 0, rr = q[2] * q[2];
            auto it =
                lower_bound(begin(sp), end(sp), array<int, 2>{q[0] - q[2], 0});

            for (; it != end(sp) && (*it)[0] <= q[0] + q[2]; ++it) {
                auto coord = *it;
                cnt += (q[0] - coord[0]) * (q[0] - coord[0]) +
                           (q[1] - coord[1]) * (q[1] - coord[1]) <=
                       rr;
            }
            res.push_back(cnt);
        }
        return res;
    }
};