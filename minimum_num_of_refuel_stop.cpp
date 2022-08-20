// 871. Minimum Number of Refueling Stops

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int i{}, res{};
        int curFuel = startFuel;
        priority_queue<int> pq;

        for (res = 0; curFuel < target; res++)
        {
            while (i < stations.size() && stations[i][0] <= curFuel)
                pq.push(stations[i++][1]);

            if (pq.empty())
                return -1;

            curFuel += pq.top();
            pq.pop();
        }

        return res;
    }
};