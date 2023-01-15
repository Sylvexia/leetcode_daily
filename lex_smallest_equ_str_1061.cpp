// 1061. Lexicographically Smallest Equivalent String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int union_find(vector<int> &parent, int node)
    {
        if (node == parent[node])
            return node;
        parent[node] = union_find(parent, parent[node]);
        return parent[node];
    }

    void union_merge(vector<int> &parent, int a, int b)
    {
        int root_a = union_find(parent, a), root_b = union_find(parent, b);

        if (root_a != root_b)
            parent[max(root_a, root_b)] = min(root_a, root_b);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        for (int i = 0; i < s1.size(); ++i)
            union_merge(parent, s1[i] - 'a', s2[i] - 'a');

        for (int i = 0; i < baseStr.size(); ++i)
            baseStr[i] = union_find(parent, baseStr[i] - 'a') + 'a';

        return baseStr;
    }
};