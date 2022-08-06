// 458. Poor Pigs
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int pigs = 0;
        int trial = (minutesToTest / minutesToDie) + 1;

        while (pow(trial, pigs) < buckets)
        {
            pigs += 1;
        }
        return pigs;
    }
};