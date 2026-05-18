// 1304. Find N Unique Integers Sum up to Zero

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res;
        if (n & 1) {
            res.push_back(0);
            n--;
        }
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};