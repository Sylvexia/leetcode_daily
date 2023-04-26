// 258. Add Digits

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int temp = num;
            int temp_res = 0;
            while (temp > 0)
            {
                temp_res += temp % 10;
                temp /= 10;
            }
            num = temp_res;
        }
        return num;
    }
};

class Solution
{
public:
    int addDigits(int num)
    {
        if (num && num % 9 == 0)
            return 9;
        return num % 9;
    }
};