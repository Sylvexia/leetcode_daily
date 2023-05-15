// 2682. Find the Losers of the Circular Game

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        unordered_set<int> u_set;
        for (int i = 0; i < n; i++)
            u_set.insert(i);

        int target = 0;
        int base_k = k;
        while (u_set.count(target))
        {
            u_set.erase(target);
            target += base_k;
            target %= n;
            base_k += k;
        }

        vector<int> res;
        for (auto ele : u_set)
            res.push_back(ele + 1);

        sort(res.begin(), res.end());

        return res;
    }
};
