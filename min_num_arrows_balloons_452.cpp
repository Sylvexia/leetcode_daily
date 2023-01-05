// 452. Minimum Number of Arrows to Burst Balloons

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int res{1}, arrow{points[0][1]};

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > arrow)
                res++, arrow = points[i][1];
        }

        return res;
    }
};