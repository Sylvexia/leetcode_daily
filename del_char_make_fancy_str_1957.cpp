// 1957. Delete Characters to Make Fancy String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string makeFancyString(string s)
    {
        string res;
        for (int i = 0; i < s.size(); i++) {
            bool all_same = true;
            for (int j = 1; j < 3; j++) {
                if (i + j >= s.size() or s[i] != s[i + j]) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same)
                res.push_back(s[i]);
        }
        return res;
    }
};