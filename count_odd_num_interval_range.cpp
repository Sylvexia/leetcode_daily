// 1523. Count Odd Numbers in an Interval Range

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return ((high + 1) >> 1) - (low >> 1);
    }
};