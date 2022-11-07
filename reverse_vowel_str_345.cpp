// 345. Reverse Vowels of a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowel_set(vowels.begin(), vowels.end());
        string str_stack = "";
        for (char ch : s)
        {
            if (vowel_set.count(ch))
            {
                str_stack.push_back(ch);
            }
        }

        for (char &ch : s)
        {
            if (vowel_set.count(ch))
            {
                ch = str_stack.back();
                str_stack.pop_back();
            }
        }

        return s;
    }
};

