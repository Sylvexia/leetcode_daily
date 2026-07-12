// 3754. Concatenate Non-Zero Digits and Multiply by Sum I

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0, sum = 0, pow10 = 1;
        while (n) {
            int mod = n % 10;
            sum += mod;
            n /= 10;
            if (mod == 0)
                continue;
            else {
                x += mod * pow10;
                pow10 *= 10;
            }
        }
        return x * sum;
    }
};