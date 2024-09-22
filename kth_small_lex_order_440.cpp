// 440. K-th Smallest in Lexicographical Order

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionTLE
{
public:
    int findKthNumber(int n, int k)
    {
        long long int res = 1;

        for (int i = 0; i < k - 1; i++) {
            if (res * 10 <= n)
                res *= 10;
            else {
                while (res % 10 == 9 or res >= n)
                    res /= 10;
                res++;
            }
        }

        return (int) res;
    }
};

class Solution
{
    int count_step(int n, long pre1, long pre2)
    {
        int res = 0;
        while (pre1 <= n) {
            res += min((long) n + 1, pre2) - pre1;
            pre1 *= 10;
            pre2 *= 10;
        }
        return res;
    }

public:
    int findKthNumber(int n, int k)
    {
        int cur = 1;
        k--;

        while (k > 0) {
            int step = count_step(n, cur, cur + 1);
            if (step > k) {
                cur *= 10;
                k--;
            } else {
                cur++;
                k -= step;
            }
        }
        return cur;
    }
};