// 834. Sum of Distances in Tree

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(int root, int pre, vector<vector<int>> &tree, vector<int> &count, vector<int> &res)
    {
        for (auto i : tree[root])
        {
            if (i == pre)
                continue;
            dfs(i, root, tree, count, res);
            count[root] += count[i];
            res[root] += (res[i] + count[i]);
        }
    }

    void dfs2(int root, int pre, vector<vector<int>> &tree, vector<int> &count, vector<int> &res)
    {
        for (auto i : tree[root])
        {
            if (i == pre)
                continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root, tree, count, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> tree(n);
        vector<int> res(n, 0), count(n, 1);

        for (auto e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(0, -1, tree, count, res);
        dfs2(0, -1, tree, count, res);
        return res;
    }
};