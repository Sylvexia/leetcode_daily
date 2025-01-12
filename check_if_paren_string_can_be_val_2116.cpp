// 2116. Check if a Parentheses String Can Be Valid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool val(string &s, string locked, char op)
    {
        int bal = 0;
        int wild = 0;
        int sz = s.size();
        int start = op == '(' ? 0 : sz - 1;
        int dir = op == '(' ? 1 : -1;

        for (int i = start; i >= 0 and i < sz and wild + bal >= 0; i += dir) {
            if (locked[i] == '1')
                bal += s[i] == op ? 1 : -1;
            else
                ++wild;
        }
        return abs(bal) <= wild;
    }

public:
    bool canBeValid(string s, string locked)
    {
        return s.size() % 2 == 0 and val(s, locked, '(') and
               val(s, locked, ')');
    }
};