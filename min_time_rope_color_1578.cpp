// 1578. Minimum Time to Make Rope Colorful

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = 0, max_cost = 0;
        for (int i = 0; i < neededTime.size(); i++)
        {
            if (i > 0 && colors[i] != colors[i - 1])
            {
                max_cost = 0;
            }
            res += min(max_cost, neededTime[i]);
            max_cost = max(max_cost, neededTime[i]);
        }
        return res;
    }
};