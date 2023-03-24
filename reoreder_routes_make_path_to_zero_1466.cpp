// 1466. Reorder Routes to Make All Paths Lead to the City Zero

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(const int node, const int parent,
            const vector<vector<pair<int, int>>> &graph)
    {
        int count = 0;
        for (const auto [ch, isreorder] : graph.at(node))
        {
            if (ch == parent)
                continue;
            count += (isreorder + dfs(ch, node, graph));
        }
        return count;
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto c : connections)
        {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }

        return dfs(0, -1, graph);
    }
};