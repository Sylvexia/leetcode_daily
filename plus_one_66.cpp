// 66. Plus One

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        vector<int> power_of_10(digits.size() + 1, 0);
        power_of_10[0] = 1;
        return power_of_10;
    }
};