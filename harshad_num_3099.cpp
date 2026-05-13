// 3099. Harshad Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int sum = 0;
        int temp = x;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }

        return (x % sum) ? -1 : sum;
    }
};