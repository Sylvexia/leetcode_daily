// 1976. Number of Ways to Arrive at Destination

#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

using pii = pair<int, int>;
using pli = pair<long long, int>;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pii>> graph(n);
        for (auto &r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;

        while (pq.size()) {
            auto [curCost, curNode] = pq.top();
            pq.pop();

            for (auto [vert, edge] : graph[curNode]) {
                if (dist[vert] > dist[curNode] + edge) {
                    dist[vert] = dist[curNode] + edge;
                    pq.push({dist[vert], vert});
                    path[vert] = path[curNode] % MOD;
                } else if (dist[vert] == curCost + edge) {
                    path[vert] += path[curNode];
                    path[vert] %= MOD;
                }
            }
        }
        return path[n - 1];
    }
};