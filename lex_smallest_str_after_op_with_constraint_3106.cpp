// 3106. Lexicographically Smallest String After Operations With Constraint

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        for (char &ch : s) {
            int dist = min(ch - 'a', 26 - (ch - 'a'));
            if (dist <= k) {
                k -= dist;
                ch = 'a';

            } else {
                ch -= k;
                k = 0;
            }
        }
        return s;
    }
};