// 3372. Maximize the Number of Target Nodes After Connecting Trees I

#include <bits/stdc++.h>

using namespace std;

vector<int> getValVec(vector<vector<int>> &graph, int maxDepth)
{
    int n = graph.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        vector<int> visited(n);

        q.push({i, 0});
        int numVal = 1;
        visited[i] = true;

        while (q.size()) {
            auto [front, dist] = q.front();
            q.pop();
            if (dist == maxDepth)
                continue;
            for (int ch : graph[front]) {
                if (visited[ch])
                    continue;
                q.push({ch, dist + 1});
                numVal++;
                visited[ch] = true;
            }
        }

        res[i] = numVal;
    }

    return res;
}

vector<vector<int>> buildGraph(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector<int>> res(n);
    for (auto &e : edges) {
        res[e[0]].push_back(e[1]);
        res[e[1]].push_back(e[0]);
    }
    return res;
}

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2,
                               int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> graph1 = buildGraph(edges1);
        vector<vector<int>> graph2 = buildGraph(edges2);

        if (k == 0)
            return vector(n, 1);

        vector<int> val1 = getValVec(graph1, k);
        vector<int> val2 = getValVec(graph2, k - 1);

        vector<int> res(n);
        int maxVal2 = *max_element(val2.begin(), val2.end());

        for (int i = 0; i < n; i++) {
            res[i] = maxVal2 + val1[i];
        }
        return res;
    }
};