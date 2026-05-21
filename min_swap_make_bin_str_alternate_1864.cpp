// 1864. Minimum Number of Swaps to Make the Binary String Alternating

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSwaps(string s)
    {
        int zeros = 0;
        int ones = 0;
        int n = s.size();
        for (char ch : s) {
            zeros += ch == '0';
            ones += ch == '1';
        }

        if (abs(zeros - ones) > 1)
            return -1;

        int miss0 = 0, miss1 = 0;
        for (int i = 0; i < n; i += 2) {
            miss0 += s[i] != '0';
            miss1 += s[i] != '1';
        }
        if (zeros == ones)
            return min(miss0, miss1);

        if (zeros > ones)
            return miss0;

        return miss1;
    }
};