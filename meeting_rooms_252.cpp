// 252. Meeting Rooms

//lint: 920 · Meeting Rooms

#include <bits/stdc++.h>

using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](Interval &a, Interval &b)
             { return a.end < b.end; });

        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i].start < intervals[0].end)
                return false;
        }

        return true;
    }
};
