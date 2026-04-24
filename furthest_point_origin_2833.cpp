// 2833. Furthest Point From Origin

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int l = 0, r = 0, u = 0;
        for (auto ch : moves) {
            l += ch == 'L';
            r += ch == 'R';
            u += ch == '_';
        }
        if (l > r)
            return l + u - r;
        return r + u - l;
    }
};