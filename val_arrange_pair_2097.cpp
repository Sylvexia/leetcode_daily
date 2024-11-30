// 2097. Valid Arrangement of Pairs

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void dfs(int node,
             unordered_map<int, vector<int>> &graph,
             vector<vector<int>> &res)
    {
        while (graph[node].size()) {
            int child = graph[node].back();
            graph[node].pop_back();
            dfs(child, graph, res);
            res.push_back({node, child});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (auto &p : pairs) {
            graph[p[0]].push_back(p[1]);
            indegree[p[0]]++;
            indegree[p[1]]--;
        }
        int start = -1;
        for (auto [node, degree] : indegree)
            if (degree > 0)
                start = node;

        if (start == -1)
            start = pairs[0][0];

        vector<vector<int>> res;
        dfs(start, graph, res);
        reverse(res.begin(), res.end());
        return res;
    }
};