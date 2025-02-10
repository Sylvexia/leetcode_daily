// 3174. Clear Digits

#include <bits/stdc++.h>
#include <cctype>

using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        string res;
        for (char ch : s) {
            if (isdigit(ch) and res.size() and !isdigit(res.back()))
                res.pop_back();
            else
                res.push_back(ch);
        }
        return res;
    }
};