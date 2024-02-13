// 547. Number of Provinces

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<bool> visited;
    void dfs(vector<vector<int>> &graph, int node)
    {
        if (visited[node])
            return;
        visited[node] = true;
        for (int child : graph[node]) {
            dfs(graph, child);
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<vector<int>> graph(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] and i != j)
                    graph[i].push_back(j);
            }
        }

        visited.resize(graph.size(), false);

        int res = 0;
        for (int node = 0; node < graph.size(); node++) {
            if (!visited[node]) {
                dfs(graph, node);
                res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.findCircleNum(data);
}