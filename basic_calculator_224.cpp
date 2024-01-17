// 224. Basic Calculator

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool is_digit(char ch) { return ch >= '0' and ch <= '9'; }

public:
    int calculate(string s)
    {
        stack<int> stk;  // for { +/- (}
        stk.push(1);
        int temp_num = 0;
        int cur_sign = 1;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (is_digit(s[i]))
                temp_num = temp_num * 10 + (s[i] - '0');
            else {
                res += (temp_num * cur_sign * stk.top());
                temp_num = 0;
                if (s[i] == '+')
                    cur_sign = 1;
                else if (s[i] == '-')
                    cur_sign = -1;
                else if (s[i] == ')')
                    stk.pop();
                else if (s[i] == '(') {
                    stk.push(stk.top() * cur_sign);
                    cur_sign = 1;
                }
            }
        }
        res += temp_num * cur_sign * stk.top();
        return res;
    }
};