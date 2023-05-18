// 1557. Minimum Number of Vertices to Reach All Nodes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        unordered_set<int> u_set;
        for (int i = 0; i < n; i++)
            u_set.insert(i);

        for (auto &e : edges)
            u_set.erase(e[1]);

        return {u_set.begin(), u_set.end()};
    }
};