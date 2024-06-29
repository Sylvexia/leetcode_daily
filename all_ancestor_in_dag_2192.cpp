// 2192. All Ancestors of a Node in a Directed Acyclic Graph

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void dfs(int node,
             int curr,
             vector<vector<int>> &res,
             vector<vector<int>> &childs)
    {
        for (auto &ch : childs[curr]) {
            if (res[ch].size() == 0 or res[ch].back() != node) {
                res[ch].push_back(node);
                dfs(node, ch, res, childs);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> res(n), childs(n);
        for (auto &e : edges)
            childs[e[0]].push_back(e[1]);
        for (int i = 0; i < n; i++)
            dfs(i, i, res, childs);
        return res;
    }
};