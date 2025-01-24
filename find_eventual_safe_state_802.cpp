// 802. Find Eventual Safe States

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool dfs(int i, vector<int> &cache, vector<vector<int>> &graph)
    {
        if (cache[i] != 0)
            return cache[i] == 1;
        cache[i] = 2;
        for (int child : graph[i])
            if (!dfs(child, cache, graph))
                return false;

        cache[i] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> cache(n);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dfs(i, cache, graph))
                res.push_back(i);
        }
        return res;
    }
};