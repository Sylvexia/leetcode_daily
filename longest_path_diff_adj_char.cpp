// 2246. Longest Path With Different Adjacent Characters

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(vector<vector<int>> &graph, int node, string &s, int &res)
    {
        int max{0}, max_2{0};
        for (auto child : graph[node])
        {
            int cur{dfs(graph, child, s, res)};

            if (s[child] == s[node])
                continue;

            if (cur > max_2)
                max_2 = cur;
            if (max_2 > max)
                swap(max, max_2);
        }
        res = std::max(res, max + max_2 + 1);
        return max + 1;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> graph(parent.size());

        for (int i = 1; i < parent.size(); i++)
            graph[parent[i]].push_back(i);

        int res{0};
        dfs(graph, 0, s, res);
        return res;
    }
};