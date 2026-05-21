// 2546. Apply Bitwise Operations to Make Strings Equal

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool makeStringsEqual(string s, string target)
    {
        bool in{false}, out{false};

        for (char c : s)
            if (c == '1')
                in = true;
        for (char c : target)
            if (c == '1')
                out = true;

        return ((in) and (out)) or (!in and !out);
    }
};