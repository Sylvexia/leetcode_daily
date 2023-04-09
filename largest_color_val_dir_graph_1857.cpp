// 1857. Largest Color Value in a Directed Graph

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(int i, string &colors,
            vector<vector<int>> &graph,
            vector<vector<int>> &count,
            vector<int> &visited)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            for (auto ch : graph[i])
            {
                if (dfs(ch, colors, graph, count, visited) == INT_MAX)
                    return INT_MAX;
                for (int k = 0; k < 26; ++k)
                    count[i][k] = max(count[i][k], count[ch][k]);
            }
            count[i][colors[i] - 'a']++;
            visited[i] = 2;
        }
        return visited[i] == 2 ? count[i][colors[i] - 'a'] : INT_MAX;
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(colors.size()),
            count(colors.size(), vector<int>(26));

        vector<int> visited(colors.size());

        for (auto &e : edges)
            graph[e[0]].push_back(e[1]);

        int res = 0;
        for (int i = 0; i < colors.size() and res != INT_MAX; i++)
            res = max(res, dfs(i, colors, graph, count, visited));

        return res == INT_MAX ? -1 : res;
    }
};