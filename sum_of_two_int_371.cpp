// 371. Sum of Two Integers

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0;
        int carry = 1;

        while (carry != 0)
        {
            sum = a ^ b;
            carry = a & b;

            b = ((unsigned int)carry) << 1;
            a = sum;
        }

        return sum;
    }
};