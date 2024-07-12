// 1717. Maximum Score From Removing Substrings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        int a = 0, b = 0, res = 0;
        for (char c : s) {
            if (c == 'a')
                a++;
            else if (c == 'b') {
                if (a)
                    res += x, a--;
                else
                    b++;
            } else {
                res += min(a, b) * y;
                a = 0;
                b = 0;
            }
        }
        return res + min(a, b) * y;
    }
};