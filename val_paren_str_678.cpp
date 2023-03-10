// 678. Valid Parenthesis String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*' or s[i] == '(')
                left++;
            else
                left--;

            if (s[s.size() - i - 1] == '*' or s[s.size() - i - 1] == ')')
                right++;
            else
                right--;

            if (left < 0 or right < 0)
                return false;
        }
        return true;
    }
};