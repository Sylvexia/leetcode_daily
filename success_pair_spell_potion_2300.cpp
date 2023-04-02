// 2300. Successful Pairs of Spells and Potions

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> ret(spells.size(), 0);

        for (int i = 0; i < spells.size(); i++)
        {
            int l = 0;
            int r = potions.size() - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                long long prod = (long long)spells[i] * (long long)potions[m];
                if (prod >= success)
                    r = m - 1;
                else
                    l = m + 1;
            }
            ret[i] = potions.size() - l;
        }

        return ret;
    }
};