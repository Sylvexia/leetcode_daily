// 826. Most Profit Assigning Work

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty,
                            vector<int> &profit,
                            vector<int> &worker)
    {
        vector<pair<int, int>> jobs;
        int n = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < n; j++) {
            jobs.push_back({difficulty[j], profit[j]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        for (int ability : worker) {
            while (i < n and ability >= jobs[i].first)
                best = max(jobs[i++].second, best);
            res += best;
        }
        return res;
    }
};