// 3870. Count Commas in Range

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countCommas(int n)
    {
        if (n / 1000 == 0)
            return 0;
        return n - 999;
    }
};