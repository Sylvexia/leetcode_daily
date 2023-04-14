// 169. Majority Element

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, ret = INT_MIN;

        for (auto n : nums)
        {
            if (count == 0)
                ret = n;
            count += (ret == n) ? 1 : -1;
        }
        return ret;
    }
};