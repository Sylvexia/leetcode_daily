// 2710. Remove Trailing Zeros From a String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if (num.back() == '0')
                num.pop_back();
        }
        return num;
    }
};