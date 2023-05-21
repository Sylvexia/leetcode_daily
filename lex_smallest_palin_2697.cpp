// 2697. Lexicographically Smallest Palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                char ch = min(s[l], s[r]);
                s[l] = ch;
                s[r] = ch;
            }

            l++;
            r--;
        }
        return s;
    }
};