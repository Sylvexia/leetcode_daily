// 210. Course Schedule II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n), res;

        for (auto &p : pre)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        function<void(int)> dfs = [&](int cur)
        {
            res.push_back(cur);
            indegree[cur] = -1;
            for (auto next : graph[cur])
            {
                if (--indegree[next] == 0)
                    dfs(next);
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                dfs(i);
        }

        if (res.size() == n)
            return res;
            
        return {};
    }
};