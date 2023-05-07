// 1964. Find the Longest Valid Obstacle Course at Each Position

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> lis;
        for (int i = 0; i < obstacles.size(); i++)
        {
            if (lis.empty() or lis[lis.size() - 1] <= obstacles[i])
            {
                lis.push_back(obstacles[i]);
                obstacles[i] = lis.size();
            }
            else
            {
                int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
                lis[idx] = obstacles[i];
                obstacles[i] = idx + 1;
            }
        }

        return obstacles;
    }
};