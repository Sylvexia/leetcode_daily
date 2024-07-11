// 1190. Reverse Substrings Between Each Pair of Parentheses

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string reverseParentheses(string s)
    {
        vector<int> offset;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                offset.push_back(res.size());
            else if (s[i] == ')') {
                int back = offset.back();
                offset.pop_back();
                reverse(res.begin() + back, res.end());
            } else
                res.push_back(s[i]);
        }
        return res;
    }
};