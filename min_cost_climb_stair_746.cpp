// 746. Min Cost Climbing Stairs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        int front_2 = cost[0], front_1 = cost[1], cur = 0;
        for (int i = 2; i < cost.size(); i++)
        {
            cur = min(front_1, front_2) + cost[i];
            front_2 = front_1;
            front_1 = cur;
        }

        return min(front_1, front_2);
    }
};