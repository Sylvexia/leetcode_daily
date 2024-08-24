// 32. Longest Valid Parentheses

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                stk.push(i);
            } else if (ch == ')') {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    res = max(res, i - stk.top());
            }
        }
        return res;
    }
};