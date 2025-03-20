// 3108. Minimum Cost Walk in Weighted Graph

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class DSU
{
public:
    vector<int> rank, parents;

    DSU(int n)
    {
        rank.resize(n, 1);
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }
    int find(int u)
    {
        if (parents[u] != u)
            return parents[u] = find(parents[u]);
        return parents[u];
    }
    bool unite(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parents[pu] = pv;
        else if (rank[pv] < rank[pu])
            parents[pv] = pu;
        else {
            parents[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution
{
public:
    vector<int> minimumCost(int n,
                            vector<vector<int>> &edges,
                            vector<vector<int>> &query)
    {
        DSU dsu(n);
        vector<int> res;

        vector<unsigned int> cost(n, -1);
        for (auto &e : edges)
            dsu.unite(e[0], e[1]);

        for (auto &e : edges) {
            int root = dsu.find(e[0]);
            cost[root] &= e[2];
        }

        for (auto &q : query) {
            if (dsu.find(q[0]) != dsu.find(q[1]))
                res.push_back(-1);
            else {
                int root = dsu.find(q[0]);
                res.push_back(cost[root]);
            }
        }
        return res;
    }
};