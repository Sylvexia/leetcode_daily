// 399. Evaluate Division

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string &src, string &dst, unordered_set<string> &visited)
    {
        if (graph.find(src) == graph.end())
            return -1;

        if (src == dst)
            return 1;

        for (auto [child, val] : graph[src])
        {
            if (visited.count(child))
                continue;
            visited.insert(child);
            double res = dfs(child, dst, visited);
            if (res != -1)
                return res * val;
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, (double)1 / val});
        }

        vector<double> res;
        for (auto &q : queries)
        {
            unordered_set<string> visited;
            res.push_back(dfs(q[0], q[1], visited));
        }
        return res;
    }
};