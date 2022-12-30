// 797. All Paths From Source to Target

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &graph,
             vector<vector<int>> &res, vector<int> &path,
             int cur)
    {

        path.push_back(cur);

        if (cur == graph.size() - 1)
            res.push_back(path);
        else
        {
            for (auto ch : graph[cur])
                dfs(graph, res, path, ch);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }
};