// 8. String to Integer (atoi)

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        while (i < s.size() and s[i] == ' ')
            i++;

        if (i < s.size() and (s[i] == '-' or s[i] == '+'))
        {
            sign *= (s[i] == '-') ? -1 : 1;
            i++;
        }

        int res = 0;
        while (i < s.size() and s[i] >= '0' and s[i] <= '9')
        {
            int digit = s[i] - '0';

            if (res > (INT_MAX - digit) / 10)
                return sign == -1 ? INT_MIN : INT_MAX;

            res = res * 10 + digit;

            i++;
        }

        return sign * res;
    }
};

int main()
{
    Solution sol;
    cout<<sol.myAtoi("+-12");
}