// 2486. Append Characters to String to Make Subsequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int t_idx = 0;
        for (int i = 0; i < s.size() and t_idx < t.size(); i++) {
            t_idx += s[i] == t[t_idx];
        }
        return t.size() - t_idx;
    }
};