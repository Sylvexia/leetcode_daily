// 1833. Maximum Ice Cream Bars

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int remain{coins}, res{0};
        for (auto c : costs)
        {
            remain -= c;
            if (remain < 0)
                return res;
            res++;
        }
        return costs.size();
    }
};