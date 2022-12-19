// 1971. Find if Path Exists in Graph

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int find_parent(int u, vector<int> &parent)
    {
        if (parent[u] == u)
            return u;
        else
            parent[u] = find_parent(parent[u], parent);

        return parent[u];
    }
    void make_same_group(int u, int v, vector<int> &parent)
    {
        int pu = find_parent(u, parent);
        int pv = find_parent(v, parent);
        parent[pu] = pv;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> parent(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto e : edges)
            make_same_group(e[0], e[1], parent);

        return find_parent(source, parent) == find_parent(destination, parent);
    }
};