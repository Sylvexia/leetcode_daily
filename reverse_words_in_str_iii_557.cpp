// 557. Reverse Words in a String III

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string temp_str, res;

        for (auto ch : s) {
            if (ch == ' ') {
                reverse(temp_str.begin(), temp_str.end());
                res = res + temp_str + " ";
                temp_str = "";
            } else
                temp_str.push_back(ch);
        }

        reverse(temp_str.begin(), temp_str.end());
        
        return res + temp_str;
    }
};