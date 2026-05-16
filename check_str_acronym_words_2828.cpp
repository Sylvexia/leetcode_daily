// 2828. Check if a String Is an Acronym of Words

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        string acro;
        for (auto &w : words) {
            acro += w[0];
        }
        return acro == s;
    }
};