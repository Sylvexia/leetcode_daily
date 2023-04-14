// 844. Backspace String Compare

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        vector<char> a, b;
        for (auto ch : s)
        {
            if (ch == '#' and a.empty())
                continue;

            if (ch == '#')
                a.pop_back();
            else
                a.push_back(ch);
        }

        for (auto ch : t)
        {
            if (ch == '#' and b.empty())
                continue;

            if (ch == '#')
                b.pop_back();
            else
                b.push_back(ch);
        }

        return a == b;
    }
};