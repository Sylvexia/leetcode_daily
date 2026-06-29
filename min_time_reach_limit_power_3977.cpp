// 3977. Minimum Time to Reach Target With Limited Power

#include <iostream>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<long long> minTimeMaxPower(int n,
                                      vector<vector<int>> &edges,
                                      int power,
                                      vector<int> &cost,
                                      int source,
                                      int target)
    {
        if (source == target)
            return {0, power};

        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            graph[u].push_back({v, t});
        }

        vector<vector<long long>> dist(n + 1,
                                       vector<long long>(power + 1, 1e18));
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>
            pq;

        dist[source][power] = 0;
        pq.push({0, -power, source});

        while (pq.size()) {
            const auto top = pq.top();
            pq.pop();
            long long t = top[0], p = -top[1], node = top[2];

            if (t > dist[node][p])
                continue;
            if (node == target)
                return {t, p};
            if (p < cost[node])
                continue;

            int new_power = p - cost[node];
            for (auto &[u, w] : graph[node]) {
                if (dist[u][new_power] <= t + w)
                    continue;
                dist[u][new_power] = t + w;
                pq.push({t + w, -new_power, u});
            }
        }

        return {-1, -1};
    }
};