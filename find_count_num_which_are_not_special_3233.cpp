// 3233. Find the Count of Numbers Which Are Not Special

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int nonSpecialCount(int l, int r)
    {
        int limit = sqrt(r);

        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }

        int special = 0;

        for (long long p = 2; p <= limit; p++) {
            if (!isPrime[p])
                continue;
            long long sp = p * p;
            if (l <= sp and r >= sp)
                special++;
        }
        return r - l + 1 - special;
    }
};