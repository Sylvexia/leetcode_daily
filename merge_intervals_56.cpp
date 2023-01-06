// 56. Merge Intervals

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> res{intervals[0]};

        for (auto i : intervals)
        {
            if (i[0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], i[1]);
            else
                res.push_back(i);
        }

        return res;
    }
};