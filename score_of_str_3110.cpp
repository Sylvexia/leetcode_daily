// 3110. Score of a String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int scoreOfString(string s)
    {
        int res = 0;
        for (int i = 1; i < s.size(); i++)
            res += abs(s[i - 1] - s[i]);
        return res;
    }
};