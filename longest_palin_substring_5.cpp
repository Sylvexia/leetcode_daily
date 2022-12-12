// 5. Longest Palindromic Substring

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    inline bool is_palin(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        for (int win_size = n; win_size > 0; win_size--)
        {
            for (int start = 0; start + win_size <= n; start++)
            {
                if (is_palin(s, start, start + win_size - 1))
                    return s.substr(start, win_size);
            }
        }
        return "uwu";
    }
};