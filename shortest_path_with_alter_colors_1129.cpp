// 1129. Shortest Path with Alternating Colors

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : redEdges)
            graph[e[0]].push_back({e[1], 0});
        for (auto &e : blueEdges)
            graph[e[0]].push_back({e[1], 1});

        vector<int> res(n, -1);

        queue<tuple<int, int, int>> q;
        q.push({0, 0, -1}); // node, dist, color

        while (!q.empty())
        {
            const auto [node, dist, color] = q.front();
            q.pop();
            res[node] = (res[node] == -1)
                            ? dist
                            : res[node];

            for (auto &[node_2, color_2] : graph[node])
            {
                if (node_2 != -1 and color_2 != color)
                {
                    q.push({node_2, dist + 1, color_2});
                    node_2 = -1;
                }
            }
        }

        return res;
    }
};