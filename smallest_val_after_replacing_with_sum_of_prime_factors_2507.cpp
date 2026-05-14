// 2507. Smallest Value After Replacing With Sum of Prime Factors

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int sumPrimeFactor(int n)
    {
        int res = 0;

        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                res += p;
                n /= p;
            }
        }

        if (n > 1)
            res += n;

        return res;
    }

public:
    int smallestValue(int n)
    {
        while (true) {
            int next = sumPrimeFactor(n);
            if (next == n)
                return n;
            n = next;
        }
    }
};