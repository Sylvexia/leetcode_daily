// 172. Factorial Trailing Zeroes

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        int power_of_five = 5;
        while (power_of_five <= n) {
            res += n / power_of_five;
            power_of_five *= 5;
        }
        return res;
    }
};