// 3243. Shortest Distance After Road Addition Queries I

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int i, vector<vector<int>> &graph, vector<int> &cost)
    {
        if (i == graph.size() - 1)
            return 0;
        if (cost[i] != -1)
            return cost[i];
        int res = INT_MAX;
        for (auto child : graph[i]) {
            res = min(res, dfs(child, graph, cost) + 1);
        }
        return cost[i] = res;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }
        vector<int> cost(n, -1);

        vector<int> res;
        for (auto &q : queries) {
            graph[q[0]].push_back(q[1]);
            int cur_res = dfs(0, graph, cost);
            res.push_back(cur_res);
            cost = vector<int>(n, -1);
        }
        return res;
    }
};