// 171. Excel Sheet Column Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int res = 0;
        for (char c : columnTitle) {
            res *= 26;
            int num = c - 'A' + 1;
            res += num;
        }
        return res;
    }
};