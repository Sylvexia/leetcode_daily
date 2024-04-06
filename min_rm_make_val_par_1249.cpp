// 1249. Minimum Remove to Make Valid Parentheses

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')') {
                if (cnt == 0)
                    s[i] = '#';
                else
                    cnt--;
            }
        }

        cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')')
                cnt++;
            else if (s[i] == '(') {
                if (cnt == 0)
                    s[i] = '#';
                else
                    cnt--;
            }
        }

        string res;
        for (char ch : s) {
            if (ch != '#')
                res.push_back(ch);
        }
        return res;
    }
};