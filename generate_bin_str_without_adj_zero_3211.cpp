// 3211. Generate Binary Strings Without Adjacent Zeros

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void backtrack(int i, int n, bool prevZero, string str, vector<string> &res)
    {
        if (i == n) {
            res.push_back(str);
            return;
        }

        if (prevZero)
            backtrack(i + 1, n, false, str + "1", res);
        else {
            backtrack(i + 1, n, true, str + "0", res);
            backtrack(i + 1, n, false, str + "1", res);
        }
        return;
    }

public:
    vector<string> validStrings(int n)
    {
        vector<string> res;
        string str = "";
        backtrack(0, n, false, str, res);
        return res;
    }
};