// 3794. Reverse String Prefix

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string reversePrefix(string s, int k)
    {
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};