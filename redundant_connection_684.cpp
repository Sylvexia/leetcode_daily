// 684. Redundant Connection

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int find(int node, vector<int> &parents)
    {
        if (parents[node] == -1)
            return node;
        return parents[node] = find(parents[node], parents);
    }

    bool is_union_cycle(int x, int y, vector<int> &parents, vector<int> &ranks)
    {
        int root_x = find(x, parents);
        int root_y = find(y, parents);
        if (root_x == root_y)
            return true;
        else if (ranks[root_x] > ranks[root_y])
        {
            parents[root_y] = root_x;
            ranks[root_x]++;
            return false;
        }
        else
        {
            parents[root_x] = root_y;
            ranks[root_y]++;
            return false;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parents(edges.size(), -1), ranks(edges.size(), 0);

        for (auto e : edges)
        {
            int x = e[0], y = e[1];
            if (is_union_cycle(x - 1, y - 1, parents, ranks))
                return {x, y};
        }

        return {-1, -1};
    }
};