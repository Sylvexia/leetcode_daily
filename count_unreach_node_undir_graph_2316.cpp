// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    class DSU
    {
    public:
        vector<int> rank;
        vector<int> parent;
        int num_group;

        DSU(int n)
            : rank(n, 0), parent(n), num_group(n)
        {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int node)
        {
            if (parent[node] == node)
                return node;
            return parent[node] = find(parent[node]);
        }

        void unite(int a, int b)
        {
            int pa = find(a);
            int pb = find(b);

            if (pa == pb)
                return;

            if (rank[pa] > rank[pb])
                parent[pb] = parent[pa];
            else if (rank[pb] > rank[pa])
                parent[pa] = parent[pb];
            else
            {
                parent[pb] = parent[pa];
                rank[pa]++;
            }
            num_group--;
        }
    };

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        DSU dsu(n);
        for (auto e : edges)
            dsu.unite(e[0], e[1]);

        unordered_map<int, int> comp_size;

        for (int i = 0; i < n; i++)
            comp_size[dsu.find(i)]++;

        long long res = 0, remain = n;
        for (auto [node, count] : comp_size)
        {
            res += count * (remain - count);
            remain -= count;
        }

        return res;
    }
};