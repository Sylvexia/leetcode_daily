// 2699. Modify Graph Edge Weights

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    const int INF = 2e9;
    int dijkstra(int n, int src, int dst, vector<vector<pair<int, int>>> &graph)
    {
        vector<int> min_dists(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;
        min_dists[src] = 0;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [cost, u] = minHeap.top();
            minHeap.pop();

            if (cost > min_dists[u])
                continue;

            for (const auto &[v, weight] : graph[u]) {
                if (cost + weight >= min_dists[v])
                    continue;
                min_dists[v] = cost + weight;
                minHeap.push({min_dists[v], v});
            }
        }

        return min_dists[dst];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n,
                                           vector<vector<int>> &edges,
                                           int source,
                                           int destination,
                                           int target)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            if (e[2] == -1)
                continue;
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int min_dist = dijkstra(n, source, destination, graph);
        if (min_dist < target)
            return vector<vector<int>>();

        bool eq_target = (min_dist == target);

        for (auto &e : edges) {
            if (e[2] != -1)
                continue;

            e[2] = eq_target ? INF : 1;
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});

            if (!eq_target) {
                int new_dist = dijkstra(n, source, destination, graph);
                if (new_dist <= target) {
                    eq_target = true;
                    e[2] += target - new_dist;
                }
            }
        }

        return eq_target ? edges : vector<vector<int>>();
    }
};