// 1106. Parsing A Boolean Expression

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool f_not(string &s, int &i)
    {
        i += 2;
        bool res = f(s, i);
        i++;
        return !res;
    }

    bool f_and(string &s, int &i)
    {
        i += 2;
        bool res = f(s, i);
        while (s[i] != ')') {
            i++;
            res &= f(s, i);
        }
        i++;
        return res;
    }

    bool f_or(string &s, int &i)
    {
        i += 2;
        bool res = f(s, i);
        while (s[i] != ')') {
            i++;
            res |= f(s, i);
        }
        i++;
        return res;
    }

    bool f(string &s, int &i)
    {
        if (s[i] == 't') {
            i++;
            return true;
        }
        if (s[i] == 'f') {
            i++;
            return false;
        }
        if (s[i] == '!')
            return f_not(s, i);
        if (s[i] == '&')
            return f_and(s, i);
        return f_or(s, i);
    }

public:
    bool parseBoolExpr(string expression)
    {
        int i = 0;
        return f(expression, i);
    }
};