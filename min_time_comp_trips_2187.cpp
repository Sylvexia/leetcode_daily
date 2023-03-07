// 2187. Minimum Time to Complete Trips

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        auto condition = [&](long long m) -> bool
        {
            long long sum = 0;
            for (auto t : time)
                sum += m / t;

            return sum >= totalTrips;
        };

        long long l = 1, r = 1e14;
        while (l < r)
        {
            long long m = l + (r - l) / 2;
            if (condition(m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};