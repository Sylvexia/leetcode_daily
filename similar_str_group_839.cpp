// 839. Similar String Groups

#include <bits/stdc++.h>

using namespace std;

class UF
{
    vector<int> parent;
    vector<int> rank;

public:
    UF(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
};

class Solution
{
    bool similar(string &a, string &b)
    {
        int n = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i] and ++n > 2)
                return false;
        }
        return true;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        int ret = strs.size();
        UF uf(ret);
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (similar(strs[i], strs[j]) and uf.unite(i, j))
                    ret--;
            }
        }
        return ret;
    }
};