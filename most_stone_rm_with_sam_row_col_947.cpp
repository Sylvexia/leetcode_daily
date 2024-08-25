// 947. Most Stones Removed with Same Row or Column

#include <bits/stdc++.h>
#include <unordered_map>

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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        DSU dsu(n);
        unordered_map<int, int> x_coord, y_coord;  // coord -> last_node_idx

        for (int i = 0; i < stones.size(); i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            if (x_coord.find(x) != x_coord.end())
                dsu.unite(i, x_coord[x]);
            if (y_coord.find(y) != y_coord.end())
                dsu.unite(i, y_coord[y]);

            x_coord[x] = i;
            y_coord[y] = i;
        }

        unordered_set<int> pars;
        for (int i = 0; i < n; i++) {
            pars.insert(dsu.find(i));
        }
        return n - pars.size();
    }
};