// 796. Rotate String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        string concat = s + s;
        for (int i = 0; i < s.size(); i++) {
            if (goal == concat.substr(i, s.size()))
                return true;
        }
        return false;
    }
};