// 2582. Pass the Pillow

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int mod = n - 1;
        int remain = time % mod;
        int dir = (time / mod) % 2;

        if (!dir)
            return 1 + remain;
        else
            return n - remain;
    }
};