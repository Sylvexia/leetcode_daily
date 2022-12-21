// 886. Possible Bipartition

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool bfs(int i, vector<vector<int>> &graph, vector<int> &mark)
    {
        queue<int> q;

        mark[i] = 1;
        q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto v : graph[u])
            {
                if (mark[v] == mark[u])
                    return false;

                if (mark[v] != 0)
                    continue;

                mark[v] = (mark[u] == 1) ? 2 : 1;
                q.push(v);
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n);
        for (auto ele : dislikes)
        {
            graph[ele[0] - 1].push_back(ele[1] - 1);
            graph[ele[1] - 1].push_back(ele[0] - 1);
        }

        vector<int> mark(n, 0); // 0: not visited, 1, 2: group

        for (int i = 0; i < graph.size(); i++)
        {
            if (mark[i] == 0)
            {
                if (bfs(i, graph, mark) == false)
                    return false;
            }
        }

        return true;
    }
};