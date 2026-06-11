// 3558. Number of Ways to Assign Edge Weights I

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
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        int max_depth = -1;
        q.push(0);
        while (q.size()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int node = q.front();
                q.pop();
                visited[node] = true;

                for (int child : graph[node]) {
                    if (visited[child])
                        continue;
                    q.push(child);
                }
            }
            max_depth++;
        }
        int res = 1;
        constexpr int mod = 1e9 + 7;
        for (int i = 0; i < max_depth - 1; i++) {
            res *= 2;
            res %= mod;
        }
        return res;
    }
};