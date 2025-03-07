// 2523. Closest Prime Numbers in Range

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j <= right; j += i)
                isPrime[j] = 0;
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        if (primes.size() < 2)
            return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> res = {-1, -1};

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                res[0] = primes[i - 1];
                res[1] = primes[i];
            }
        }

        return res;
    }
};