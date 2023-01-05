// 253. Meeting Rooms II

// lint: 919

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
    int minMeetingRooms(vector<Interval> &intervals)
    {
        //[1,2], [1,3], [2,3], [2,4]
        vector<int> start_vec, end_vec;
        for (auto i : intervals)
        {
            start_vec.push_back(i.start);
            end_vec.push_back(i.end);
        }

        sort(start_vec.begin(), start_vec.end());
        sort(end_vec.begin(), end_vec.end());

        int s{0}, e{0}, res{0}, count{0};

        while (s < intervals.size())
        {
            if (start_vec[s] < end_vec[e])
                s++, count++;
            else
                e++, count--;
            res = max(res, count);
        }
        return res;
    }
};