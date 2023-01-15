// 2421. Number of Good Paths

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int union_find(vector<int> &parents, int node)
    {
        if (parents[node] != node)
            parents[node] = union_find(parents, parents[node]);
        return parents[node];
    }

public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        vector<int> parents(vals.size());
        vector<vector<int>> count(vals.size());
        int res{0};

        for (int i = 0; i < vals.size(); ++i)
            parents[i] = i, count[i] = {vals[i], 1};

        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b)
             { return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]); });

        for (auto &e : edges)
        {
            int a = union_find(parents, e[0]);
            int b = union_find(parents, e[1]);

            if (count[a][0] != count[b][0])
            {
                if (count[a][0] > count[b][0])
                    parents[b] = a;
                else
                    parents[a] = b;
            }
            else
            {
                parents[a] = b;
                res += count[a][1] * count[b][1];
                count[b][1] += count[a][1];
            }
        }

        return res + vals.size();
    }
};