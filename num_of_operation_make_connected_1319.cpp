// 1319. Number of Operations to Make Network Connected

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for (auto &c : connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        int num_component = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            q.push(i);
            visited[i] = true;
            num_component++;

            while (q.size())
            {
                int front = q.front();
                q.pop();

                for (const int ch : graph[front])
                {
                    if (visited[ch])
                        continue;
                    visited[ch] = true;
                    q.push(ch);
                }
            }
        }

        return num_component - 1;
    }
};

class Solution
{
    void dfs(const int node, const vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;
        for (const int ch : graph[node])
        {
            if (visited[ch])
                continue;

            dfs(ch, graph, visited);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for (auto &c : connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        int num_component = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            num_component++;

            dfs(i, graph, visited);
        }

        return num_component - 1;
    }
};