// 2477. Minimum Fuel Cost to Report to the Capital

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int dfs(int node, int prev, vector<vector<int>> &graph, int seats, long long &res)
    {
        int people{1};

        for (auto child : graph[node])
        {
            if (prev == child)
                continue;

            people += dfs(child, node, graph, seats, res);
        }

        if (node != 0) // ceil(people/seats)
            res += (people + seats - 1) / seats;

        return people;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        long long res{0};
        vector<vector<int>> graph(roads.size() + 1);

        for (const auto &r : roads)
        {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }

        dfs(0, -1, graph, seats, res);
        return res;
    }
};