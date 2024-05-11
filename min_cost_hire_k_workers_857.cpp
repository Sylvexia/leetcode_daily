// 57. Minimum Cost to Hire K Workers

#include <bits/stdc++.h>
#include <cfloat>
#include <queue>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> workers;

        for (int i = 0; i < quality.size(); i++)
            workers.push_back({double(wage[i]) / quality[i], quality[i]});

        sort(workers.begin(), workers.end());

        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;

        for (auto [ratio, quality] : workers) {
            qsum += quality;
            pq.push(quality);
            if (pq.size() > k)
                qsum -= pq.top(), pq.pop();
            if (pq.size() == k)
                res = min(res, qsum * ratio);
        }
        return res;
    }
};