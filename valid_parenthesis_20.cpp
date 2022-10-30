// 20. Valid Parentheses

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        string str_stack{};
        unordered_map<char, char> paren_map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (auto ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                str_stack.push_back(ch);
            else
            {
                if (paren_map[str_stack.back()] != ch)
                    return false;
                else
                    str_stack.pop_back();
            }
        }

        if (!str_stack.empty())
            return false;
            
        return true;
    }
};