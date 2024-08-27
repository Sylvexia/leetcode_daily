// 1514. Path with Maximum Probability

#include <bits/stdc++.h>
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
    double maxProbability(int n,
                          vector<vector<int>> &edges,
                          vector<double> &succProb,
                          int start_node,
                          int end_node)
    {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            graph[e[0]].push_back({e[1], succProb[i]});
            graph[e[1]].push_back({e[0], succProb[i]});
        }
        vector<int> seen(n, 0);
        vector<double> max_vec(n, (double) 0.0);

        priority_queue<pair<double, int>> q;
        q.push({double(1.0), start_node});

        while (!q.empty()) {
            auto [prob, node] = q.top();
            q.pop();
            if (!seen[node]) {
                seen[node] = true;
                for (auto [child_edge, child_prob] : graph[node]) {
                    double new_prob = prob * child_prob;
                    if (new_prob > max_vec[child_edge]) {
                        max_vec[child_edge] = new_prob;
                        q.push({max_vec[child_edge], child_edge});
                    }
                }
            }
        }
        return max_vec[end_node];
    }
};