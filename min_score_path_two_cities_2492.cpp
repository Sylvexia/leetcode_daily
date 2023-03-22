// 2492. Minimum Score of a Path Between Two Cities

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto &r : roads)
        {
            graph[r[0]][r[1]] = r[2];
            graph[r[1]][r[0]] = r[2];
        }

        int res = INT_MAX;
        unordered_set<int> visited;
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &[adj, score] : graph[node])
            {
                if (!visited.count(adj))
                {
                    q.push(adj);
                    visited.insert(adj);
                }
                res = min(res, score);
            }
        }

        return res;
    }
};