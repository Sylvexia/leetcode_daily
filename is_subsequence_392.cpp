// 392. Is Subsequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "")
            return true;
        int index = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[index])
                index++;

            if (index == s.size())
                return true;
        }
        return false;
    }
};