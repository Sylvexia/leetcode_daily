// 3783. Mirror Distance of an Integer

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int rev(int n)
    {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }

public:
    int mirrorDistance(int n) { return abs(n - rev(n)); }
};