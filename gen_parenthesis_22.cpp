// 22. Generate Parentheses

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }

    void backtrack(int open, int closed, int n, string cur, vector<string> &res)
    {
        if ((open == closed) && (closed == n))
        {
            res.push_back(cur);
            return;
        }
        if (open < n)
            backtrack(open + 1, closed, n, cur + "(", res);
        if (closed < open)
            backtrack(open, closed + 1, n, cur + ")", res);
    }
};