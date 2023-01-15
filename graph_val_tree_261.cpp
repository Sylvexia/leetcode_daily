// 261. Graph Valid Tree

// lint:178

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool has_cycle(vector<vector<int>> &adj, vector<bool> &visited, int parent, int node)
    {
        if (visited[node])
            return true;

        visited[node] = true;

        for (int child : adj[node])
        {
            if (child != parent && has_cycle(adj, visited, node, child))
                return true;
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (auto e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        if (has_cycle(adjList, visited, -1, 0))
            return false;

        for (bool v : visited)
        {
            if (!v)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    sol.validTree(5, data);
}