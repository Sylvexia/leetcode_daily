// 1519. Number of Nodes in the Sub-Tree With the Same Label

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &edges, string &labels, vector<int> &freqMap, vector<int> &res, int prev, int cur)
    {
        int prevCount = freqMap[labels[cur] - 'a'];

        freqMap[labels[cur] - 'a']++;

        for (int child : edges[cur])
        {
            if (child == prev)
                continue;

            dfs(edges, labels, freqMap, res, cur, child);
        }

        res[cur] = freqMap[labels[cur] - 'a'] - prevCount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<int> freqMap(26, 0), res(n, 0);
        vector<vector<int>> graph(n);

        for (auto ele : edges)
        {
            graph[ele[1]].push_back(ele[0]);
            graph[ele[0]].push_back(ele[1]);
        }

        dfs(graph, labels, freqMap, res, -1, 0);
        return res;
    }
};