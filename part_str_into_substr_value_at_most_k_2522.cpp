// 2522. Partition String Into Substrings With Values at Most K

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        long long cur = 0;
        int res = 1;
        for (char ch : s) {
            int digit = ch - '0';
            if (digit > k)
                return -1;
            long long next = cur * 10 + digit;
            if (next <= k)
                cur = next;
            else {
                res++;
                cur = digit;
            }
        }
        return res;
    }
};