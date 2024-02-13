// 459. Repeated Substring Pattern

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for (int i = 1; i <= s.size() / 2; i++) {
            string substring = s.substr(0, i);
            string temp;
            for (int j = 0; j < s.size() / i; j++)
                temp += substring;
            if (temp == s)
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string doubled = s + s;
        string substring = doubled.substr(1, doubled.size() - 2);
        return substring.find(s) != string::npos;
    }
};