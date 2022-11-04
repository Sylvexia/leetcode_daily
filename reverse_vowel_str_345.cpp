// 345. Reverse Vowels of a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU";
        string str_stack = "";
        for (char ch : s)
        {
            for (char vow : vowels)
            {
                if (ch == vow)
                {
                    str_stack.push_back(ch);
                    break;
                }
            }
        }

        for (char &ch : s)
        {
            for (char vow : vowels)
            {
                if (ch == vow)
                {
                    ch = str_stack.back();
                    str_stack.pop_back();
                    break;
                }
            }
        }

        return s;
    }
};