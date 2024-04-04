// 1614. Maximum Nesting Depth of the Parentheses

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxDepth(string s)
    {
        int res = 0, cur = 0;
        for (char ch : s) {
            if (ch == '(')
                cur++;
            else if (ch == ')')
                cur--;

            res = max(res, cur);
        }

        return res;
    }
};