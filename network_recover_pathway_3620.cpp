// 2608. Shortest Cycle in a Graph

#include <climits>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges,
                         vector<bool> &online,
                         long long k)
    {
        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        int l = INT_MAX, r = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (!online[u] or !online[v])
                continue;
            graph[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        auto check = [&](int m) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                           greater<>>
                pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (pq.size()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > k)
                    return false;
                if (u == n - 1)
                    return true;
                if (d > dist[u])
                    continue;
                for (auto &[v, w] : graph[u]) {
                    if (w < m)
                        continue;
                    long long newDist = dist[u] + w;
                    if (dist[v] <= newDist)
                        continue;
                    dist[v] = newDist;
                    pq.push({dist[v], v});
                }
            };
            return false;
        };

        if (!check(l))
            return -1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m))
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};