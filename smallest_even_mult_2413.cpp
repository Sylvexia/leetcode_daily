// 2413. Smallest Even Multiple

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int smallestEvenMultiple(int n) { return (n % 2) ? n * 2 : n; }
};