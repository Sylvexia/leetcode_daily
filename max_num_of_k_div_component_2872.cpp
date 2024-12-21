// 2872. Maximum Number of K-Divisible Components

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int node,
            int par,
            vector<vector<int>> &graph,
            vector<int> &values,
            int k,
            int &res)
    {
        int sum = 0;
        for (auto ch : graph[node]) {
            if (ch != par) {
                sum += dfs(ch, node, graph, values, k, res);
                sum %= k;
            }
        }
        sum += values[node];
        sum %= k;

        res += (sum == 0);
        return sum;
    }

public:
    int maxKDivisibleComponents(int n,
                                vector<vector<int>> &edges,
                                vector<int> &values,
                                int k)
    {
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(0, -1, graph, values, k, res);
        return res;
    }
};