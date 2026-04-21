// 1722. Minimize Hamming Distance After Swap Operations

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
    int find(int x)
    {
        if (parents[x] != x)
            return find(parents[x]);
        return parents[x];
    }
    bool unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
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
    int minimumHammingDistance(vector<int> &source,
                               vector<int> &target,
                               vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        DSU dsu(n);
        for (auto swap : allowedSwaps)
            dsu.unite(swap[0], swap[1]);

        unordered_map<int, unordered_map<int, int>> group;
        for (int i = 0; i < n; i++) {
            group[dsu.find(i)][source[i]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            auto &freq = group[root];
            if (freq.count(target[i]) and freq[target[i]] > 0)
                freq[target[i]]--;
            else
                res++;
            ;
        }

        return res;
    }
};