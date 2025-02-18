// 2375. Construct Smallest Number From DI String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        vector<char> stk;
        char curChar = '1';
        string res;
        for (char ch : pattern) {
            stk.push_back(curChar++);
            if (ch == 'I') {
                while (!stk.empty()) {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
            }
        }

        stk.push_back(curChar++);
        while (!stk.empty()) {
            res.push_back(stk.back());
            stk.pop_back();
        }

        return res;
    }
};