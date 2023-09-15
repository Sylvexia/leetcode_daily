// 334. Increasing Triplet Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min_1 = INT_MAX, min_2 = INT_MAX;

        for (int n : nums) {
            if (n <= min_1)
                min_1 = n;
            else if (n <= min_2)
                min_2 = n;
            else
                return true;
        }

        return false;
    }
};