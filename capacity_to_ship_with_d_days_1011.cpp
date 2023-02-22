// 1011. Capacity To Ship Packages Within D Days

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        auto feasible = [&](int capacity) -> bool
        {
            int total = 0;
            int d = 1;

            for (const int w : weights)
            {
                total += w;
                if (total > capacity)
                {
                    total = w;
                    d++;
                    if (d > days)
                        return false;
                }
            }
            return true;
        };

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (feasible(m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};