// 709. To Lower Case

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &ch : s) {
            if (ch >= 'A' and ch <= 'Z')
                ch = 'a' + (ch - 'A');
        }
        return s;
    }
};