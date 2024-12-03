// 2109. Adding Spaces to a String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res;
        int prev = 0;
        for (int i = 0; i < spaces.size(); i++) {
            auto sub = s.substr(prev, spaces[i] - prev);
            res.append(sub);
            res.push_back(' ');
            prev = spaces[i];
        }
        res.append(s.substr(prev));
        return res;
    }
};