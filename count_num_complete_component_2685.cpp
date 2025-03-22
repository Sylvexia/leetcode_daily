// 2685. Count the Number of Complete Components

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) : parent(n, 0), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node)
    {
        return node == parent[node] ? node : find(parent[node]);
    }

    void unite(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        if (rank[pa] > rank[pb])
            parent[pb] = pa;
        else if (rank[pb] > rank[pa])
            parent[pa] = pb;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        DSU dsu(n);
        for (auto &e : edges) {
            dsu.unite(e[0], e[1]);
        }

        unordered_map<int, unordered_set<int>> getVertices;
        unordered_map<int, int> numEdge;

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            getVertices[root].insert(i);
        }

        for (auto &e : edges) {
            int root = dsu.find(e[0]);
            numEdge[root]++;
        }

        int res = 0;
        for (auto &[root, vertices] : getVertices) {
            int numVer = vertices.size();
            int expected = numVer * (numVer - 1) / 2;
            res += numEdge[root] == expected;
        }
        return res;
    }
};