// 125. Valid Palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;

            while (l < r && !isalnum(s[l]))
                r--;

            if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }

        return true;
    }
};