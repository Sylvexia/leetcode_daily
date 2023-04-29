// 1697. Checking Existence of Edge Length Limited Paths

#include <bits/stdc++.h>

using namespace std;

class DSU
{
    vector<int> rank, parents;

public:
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
        else
        {
            parents[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);

        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](auto &l, auto &r)
             { return l[2] < r[2]; });
        sort(edgeList.begin(), edgeList.end(), [](auto &l, auto &r)
             { return l.back() < r.back(); });

        int i = 0;
        vector<bool> res(queries.size());
        for (auto &q : queries)
        {
            while (i < edgeList.size() and edgeList[i][2] < q[2])
                dsu.unite(edgeList[i][0], edgeList[i][1]), i++;

            res[q.back()] = (dsu.find(q[0]) == dsu.find(q[1]));
        }
        return res;
    }
};