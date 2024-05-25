// 721. Accounts Merge

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class DSU
{
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) : parent(n), rank(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[py] > rank[px])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return;
    }

    bool is_connected(int x, int y) { return find(x) == find(y); }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        DSU dsu(accounts.size());
        unordered_map<string, int> emailIdx;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string &cur_email = accounts[i][j];
                if (emailIdx.count(cur_email) == 0)
                    emailIdx[accounts[i][j]] = i;
                else
                    dsu.unite(emailIdx[cur_email], i);
            }
        }

        unordered_map<int, vector<string>> collection;

        for (auto &[email_str, idx] : emailIdx) {
            int parent_id = dsu.find(idx);
            collection[parent_id].push_back(email_str);
        }

        vector<vector<string>> res;

        for (auto &[idx, emails] : collection) {
            sort(emails.begin(), emails.end());

            string name = accounts[idx][0];
            vector<string> row = {name};
            for (auto &email : emails)
                row.push_back(email);

            res.push_back(row);
        }

        return res;
    }
};