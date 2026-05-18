// 2761. Prime Pairs With Target Sum

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            for (int j = i * i; j <= n; j += i) {
                if (!isPrime[j])
                    continue;
                isPrime[j] = false;
            }
        }

        vector<vector<int>> res;
        for (int i = 2; i <= n / 2; i++) {
            int a = i;
            int b = n - i;
            if (isPrime[a] and isPrime[b])
                res.push_back({a, b});
        }
        return res;
    }
};