// 881. Boats to Save People

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end(), greater<int>());

        int l = 0, r = people.size() - 1;
        int res = 0;

        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
                r--;
            l++;
            res++;
        }
        return res;
    }
};