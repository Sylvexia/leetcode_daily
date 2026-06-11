// 3559. Number of Ways to Assign Edge Weights II

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class LCA
{
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> graph;

    void dfs(int node, int parent)
    {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++)
            up[node][j] = up[up[node][j - 1]][j - 1];

        for (int child : graph[node]) {
            if (child == parent)
                continue;

            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

public:
    LCA(int n, vector<vector<int>> &edges) : n(n)
    {
        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        graph.assign(n, {});
        up.assign(n, vector<int>(LOG));
        depth.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, 0);
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int dist(int u, int v)
    {
        int a = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[a];
    }
};

class Solution
{
    static constexpr int MOD = 1e9 + 7;

public:
    vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                  vector<vector<int>> &queries)
    {
        int n = edges.size() + 1;

        vector<int> p2(n + 1);
        p2[0] = 1;

        for (int i = 1; i <= n; i++) {
            p2[i] = 1LL * p2[i - 1] * 2 % MOD;
        }

        LCA lca(n, edges);

        vector<int> res;

        for (auto &q : queries) {
            int u = q[0] - 1;
            int v = q[1] - 1;

            int d = lca.dist(u, v);

            if (d == 0)
                res.push_back(0);
            else
                res.push_back(p2[d - 1]);
        }

        return res;
    }
};