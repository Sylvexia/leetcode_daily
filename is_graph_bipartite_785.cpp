// 785. Is Graph Bipartite?

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (colors[i] != 0)
                continue;

            colors[i] = 1;
            q.push(i);

            while (q.size())
            {
                int front = q.front();

                for (int j = 0; j < graph[front].size(); j++)
                {
                    if (colors[graph[front][j]] == 0)
                    {
                        colors[graph[front][j]] = -colors[front];
                        q.push(graph[front][j]);
                    }

                    else if (colors[graph[front][j]] == colors[front])
                        return false;
                }

                q.pop();
            }
        }
        return true;
    }
};