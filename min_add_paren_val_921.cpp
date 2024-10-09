// 921. Minimum Add to Make Parentheses Valid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0;
        int res = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            } else {
                count--;
                if (count < 0) {
                    res++;
                    count = 0;
                }
            }
        }
        return res + count;
    }
};