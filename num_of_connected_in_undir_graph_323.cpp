// 323. Number of Connected Components in an Undirected Graph

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int find_compression(int node, vector<int> &parent)
    {
        if (node == parent[node])
            return node;
        parent[node] = find_compression(parent[node], parent);
        return parent[node];
    }

    int union_set(vector<int> &parents, vector<int> &ranks, int a, int b)
    {
        int root_a = find_compression(a, parents);
        int root_b = find_compression(b, parents);

        if (root_a == root_b)
            return 0;

        if (ranks[root_a] > ranks[root_b])
        {
            parents[root_b] = root_a;
            ranks[root_a] += ranks[root_b];
        }
        else
        {
            parents[root_a] = root_b;
            ranks[root_b] += ranks[root_a];
        }

        return 1;
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> parents, ranks;
        int res{n};

        for (int i = 0; i < n; i++)
        {
            parents.push_back(i);
            ranks.push_back(1);
        }

        for (auto e : edges)
            res -= union_set(parents, ranks, e[0], e[1]);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{1, 1}, {2, 3}, {4, 5}, {0, 0}};
    cout << sol.countComponents(6, data);
}