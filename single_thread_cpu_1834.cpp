// 1834. Single-Threaded CPU

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    struct Task {
        int enqueue;
        int process;
        int index;
    };

    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<Task> ts;
        ts.reserve(n);

        for (int i = 0; i < n; ++i) {
            ts.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(ts.begin(), ts.end(), [](const Task &a, const Task &b) {
            return a.enqueue < b.enqueue;
        });

        using PQNode = pair<int, int>;  // {process, index}
        priority_queue<PQNode, vector<PQNode>, greater<>> pq;

        vector<int> res;
        int i = 0;
        long long time = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                time = max(time, (long long) ts[i].enqueue);
            }

            while (i < n && ts[i].enqueue <= time) {
                pq.emplace(ts[i].process, ts[i].index);
                ++i;
            }

            auto [process, idx] = pq.top();
            pq.pop();

            time += process;
            res.push_back(idx);
        }

        return res;
    }
};