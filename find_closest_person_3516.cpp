// 3516. Find Closest Person

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int a = abs(x - z);
        int b = abs(y - z);
        return (a > b) ? 2 : (a < b) ? 1 : 0;
    }
};