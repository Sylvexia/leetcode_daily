// 3373. Maximize the Number of Target Nodes After Connecting Trees II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(int i,
            int parent,
            int depth,
            vector<vector<int>> &graph,
            vector<int> &color)
    {
        int res = 1 - depth % 2;
        color[i] = depth % 2;
        for (int ch : graph[i]) {
            if (ch == parent)
                continue;
            res += dfs(ch, i, depth + 1, graph, color);
        }
        return res;
    }
    vector<int> build(vector<vector<int>> &edges, vector<int> &color)
    {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int res = dfs(0, -1, 0, graph, color);
        return {res, n - res};
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        auto count1 = build(edges1, color1);
        auto count2 = build(edges2, color2);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return res;
    }
};