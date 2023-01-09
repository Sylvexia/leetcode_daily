// 435. Non-overlapping Intervals

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b)
             { return a[1] < b[1]; });

        vector<int> temp{intervals[0]};
        int res{-1};

        for (auto &i : intervals)
        {
            if (temp[1] > i[0])
                res++;
            else
                temp = i;
        }
        return res;
    }
};