// 1899. Merge Triplets to Form Target Triplet

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        array<bool, 3> res{false, false, false};

        for (auto &t : triplets)
        {
            bool skip = false;

            for (int i = 0; i < 3; i++)
            {
                if (t[i] > target[i])
                {
                    skip = true;
                    break;
                }
            }

            if (skip)
                continue;

            for (int i = 0; i < 3; i++)
                res[i] |= (target[i] == t[i]);
        }

        return res[0] && res[1] && res[2];
    }
};