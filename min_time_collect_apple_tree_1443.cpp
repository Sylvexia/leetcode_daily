// 1443. Minimum Time to Collect All Apples

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(vector<bool> &hasApple, vector<vector<int>> &graph, int node, int prev, int depth)
    {
        int res{0}, temp{0};
        for (int child : graph[node])
        {
            if (child == prev)
                continue;

            temp = dfs(hasApple, graph, child, node, depth + 1);
            if (temp)
                res += temp - depth;
        }

        return (hasApple[node] || res) ? res + depth : 0;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> graph(n);
        for (auto ele : edges)
        {
            graph[ele[0]].push_back(ele[1]);
            graph[ele[1]].push_back(ele[0]);
        }
        return dfs(hasApple, graph, 0, -1, 0) * 2;
    }
};