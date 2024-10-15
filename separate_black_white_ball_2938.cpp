// 2938. Separate Black and White Balls

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long res = 0;
        int zeros = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                res += (i - zeros);
                zeros++;
            }
        }

        return res;
    }
};