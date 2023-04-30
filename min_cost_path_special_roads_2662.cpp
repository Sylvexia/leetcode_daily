// 2662. Minimum Cost of a Path With Special Roads

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int cal_dist(int x1, int x2, int y1, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {
        int min_dist = cal_dist(start[0], target[0], start[1], target[1]);

        queue<pair<int, int>> q;

        for (int i = 0; i < specialRoads.size(); i++)
            q.push({i,
                    cal_dist(start[0], specialRoads[i][0],
                             start[1], specialRoads[i][1]) +
                        specialRoads[i][4]});

        while (q.size())
        {
            auto [idx, dst] = q.front();
            q.pop();

            if (dst > min_dist)
                continue;

            min_dist = min(min_dist,
                           dst +
                               cal_dist(specialRoads[idx][2], target[0],
                                        specialRoads[idx][3], target[1]));

            for (int i = 0; i < specialRoads.size(); i++)
            {
                if (i == idx)
                    continue;

                q.push({i, dst +
                               cal_dist(specialRoads[idx][2], specialRoads[i][0],
                                        specialRoads[idx][3], specialRoads[i][1]) +
                               specialRoads[i][4]});
            }
        }
        return min_dist;
    }
};

class Solution
{
    int cal_dist(int x1, int x2, int y1, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minimumCost(vector<int> &start, vector<int> &target,
                    vector<vector<int>> &Sroads)
    {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < Sroads.size(); i++)
            pq.push({cal_dist(target[0], Sroads[i][2], target[1], Sroads[i][3]), i});

        vector<int> dp(Sroads.size(), INT_MAX);

        while (!pq.empty())
        {
            auto [cost, i] = pq.top();
            pq.pop();

            if (dp[i] != INT_MAX)
                continue;

            dp[i] = min(dp[i], cost);

            for (int j = 0; j < Sroads.size(); j++)
            {
                if (j == i)
                    continue;
                pq.push({cost + Sroads[i][4] +
                             cal_dist(Sroads[j][2], Sroads[i][0],
                                      Sroads[j][3], Sroads[i][1]),
                         j});
            }
        }
        int res = cal_dist(start[0], target[0], start[1], target[1]);

        for (int i = 0; i < Sroads.size(); i++)
            res = min(res, Sroads[i][4] + dp[i] +
                               cal_dist(start[0], Sroads[i][0], start[1], Sroads[i][1]));

        return res;
    }
};