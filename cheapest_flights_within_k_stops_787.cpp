// 787. Cheapest Flights Within K Stops

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> cost(n, 1e8);
        cost[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> temp(cost);

            for (auto &f : flights)
                temp[f[1]] = min(temp[f[1]], cost[f[0]] + f[2]);

            cost = temp;
        }

        return (cost[dst] == 1e8) ? -1 : cost[dst];
    }
};