// 2579. Count Total Number of Colored Cells

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long res = 1;
        for (int i = 0; i < n; i++)
            res += 4 * i;
        return res;
    }
};