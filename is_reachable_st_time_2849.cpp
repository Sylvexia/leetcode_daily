// 2849. Determine if a Cell Is Reachable at a Given Time

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int a = abs(sx - fx);
        int b = abs(sy - fy);
        if (a == 0 and b == 0 and t == 1)
            return false;
        return a <= t and b <= t;
    }
};