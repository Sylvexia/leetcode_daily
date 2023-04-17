// 1431. Kids With the Greatest Number of Candies

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max = *max_element(candies.begin(), candies.end());
        max -= extraCandies;
        vector<bool> ret(candies.size(), true);

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] < max)
                ret[i] = false;
        }
        return ret;
    }
};