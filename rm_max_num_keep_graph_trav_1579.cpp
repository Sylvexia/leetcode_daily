// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

#include <bits/stdc++.h>

using namespace std;

class DSU
{
    int m_size;
    vector<int> parents;

public:
    DSU(int n)
    {
        m_size = n;
        for (int i = 0; i <= n; i++)
            parents.push_back(i);
    }

    bool unite(int u, int v)
    {
        if (find(u) == find(v))
            return false;

        parents[find(u)] = v;
        m_size--;
        return true;
    }

    int find(int u)
    {
        if (parents[u] != u)
            parents[u] = find(parents[u]);
        return parents[u];
    }

    bool united()
    {
        return (m_size == 1);
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });

        int added = 0;

        DSU bob(n), alice(n);

        for (auto &e : edges)
        {
            int e_type = e[0],
                u = e[1],
                v = e[2];

            switch (e_type)
            {
            case 3:
            {
                added += (bob.unite(u, v) | alice.unite(u, v));
                break;
            }
            case 2:
            {
                added += bob.unite(u, v);
                break;
            }
            case 1:
            {
                added += alice.unite(u, v);
                break;
            }
            }
        }

        return (bob.united() && alice.united())
                   ? (edges.size() - added)
                   : -1;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> edges =
        {
            {3, 1, 2},
            {3, 2, 3},
            {1, 1, 3},
            {1, 2, 4},
            {1, 1, 2},
            {2, 3, 4}};

    Solution sol;
    cout << sol.maxNumEdgesToRemove(n, edges);
}