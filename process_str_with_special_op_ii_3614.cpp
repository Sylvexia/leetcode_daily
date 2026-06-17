// 3614. Process String with Special Operations II

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long int l = 0;
        for (char c : s) {
            if (c == '*')
                l = max((long long) 0, l - 1);
            else if (c == '#')
                l *= 2;
            else if (c == '%')
                continue;
            else
                l += 1;
        }

        if (k >= l)
            return '.';

        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '*')
                l += 1;
            else if (c == '#') {
                l /= 2;
                if (k >= l)
                    k -= l;
            } else if (c == '%') {
                k = l - 1 - k;
            } else {
                l -= 1;
                if (l == k)
                    return c;
            }
        }

        return '.';
    }
};