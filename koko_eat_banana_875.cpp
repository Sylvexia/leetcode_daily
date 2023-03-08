// 875. Koko Eating Bananas

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        auto condition = [&](const int m) -> bool
        {
            int sum = 0;
            for (const auto &p : piles)
            {
                sum += (p / m);
                sum += (((p % m) > 0) ? 1 : 0);
            }

            return sum <= h;
        };

        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (condition(m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};