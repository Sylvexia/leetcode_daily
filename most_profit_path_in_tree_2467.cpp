// 2467. Most Profitable Path in a Tree

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> graph;
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    int res = INT_MIN;

    bool getBobPath(int i, int time)
    {
        bobPath[i] = time;
        visited[i] = true;

        if (i == 0)
            return true;

        for (int child : graph[i]) {
            if (!visited[child] and getBobPath(child, time + 1))
                return true;
        }

        bobPath.erase(i);
        return false;
    }

    void getAlicePath(int i, int time, int income, vector<int> &amount)
    {
        visited[i] = true;

        if (!bobPath.count(i) or time < bobPath[i])
            income += amount[i];
        else if (time == bobPath[i])
            income += (amount[i] / 2);

        if (graph[i].size() == 1 and i != 0)
            res = max(res, income);

        for (int child : graph[i]) {
            if (!visited[child])
                getAlicePath(child, time + 1, income, amount);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges,
                           int bob,
                           vector<int> &amount)
    {
        int n = amount.size();
        graph.resize(n);
        visited.assign(n, false);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        getBobPath(bob, 0);
        visited.assign(n, false);
        getAlicePath(0, 0, 0, amount);
        return res;
    }
};