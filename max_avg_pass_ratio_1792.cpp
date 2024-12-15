// 1792. Maximum Average Pass Ratio

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    double profit(double pass, double total)
    {
        return (pass + 1) / (total + 1) - (pass / total);
    }

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        double total = 0;
        for (auto &c : classes) {
            total += (double) c[0] / c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [delta, class_info] = pq.top();
            auto [cur_pass, cur_total] = class_info;
            pq.pop();

            total += delta;
            pq.push({profit(cur_pass + 1, cur_total + 1),
                     {cur_pass + 1, cur_total + 1}});
        }
        return total / classes.size();
    }
};