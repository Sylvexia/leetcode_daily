// 1822. Sign of the Product of an Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int res = 1;
        for (int n : nums)
        {
            res *= (n > 0) ? 1 : (n < 0) ? -1
                                         : 0;
        }
        return res;
    }
};