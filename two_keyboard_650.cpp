// 650. 2 Keys Keyboard

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSteps(int n)
    {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int idx = 10;
        int res = 0;
        while (n != 1) {
            int prime_val = primes[idx];
            if (n % prime_val == 0) {
                n /= prime_val;
                res += prime_val;
            } else
                idx--;

            if (idx < 0) {
                res += n;
                return res;
            }
        }
        return res;
    }
};