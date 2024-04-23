// 310. Minimum Height Trees

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (!edges.size())
            return {0};
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> leaves, newLeaves, inDegree;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1)
                leaves.push_back(i);
            inDegree.push_back(graph[i].size());
        }

        while (n > 2) {
            for (auto leaf : leaves) {
                for (auto child : graph[leaf]) {
                    if (--inDegree[child] == 1)
                        newLeaves.push_back(child);
                }
            }
            n -= leaves.size();
            leaves = move(newLeaves);
        }
        return leaves;
    }
};