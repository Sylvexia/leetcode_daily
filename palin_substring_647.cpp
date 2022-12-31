// 647. Palindromic Substrings

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline bool isPalin(int start, int end, string &s)
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

public:
    int countSubstrings(string &s)
    {
        int n = s.size(), res = 0;
        for (int start = 0; start < n; start++)
        {
            for (int end = start; end < n; end++)
            {
                if (isPalin(start, end, s))
                    res++;
            }
        }
        return res;
    }
};