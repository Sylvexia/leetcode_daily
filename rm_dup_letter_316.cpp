// 316. Remove Duplicate Letters

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res;
        int last[26] = {};
        bool added[26] = {};

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); i++) {
            if (added[s[i] - 'a'])
                continue;

            while (!res.empty() and res.back() > s[i] and
                   last[res.back() - 'a'] > i) {
                added[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        return res;
    }
};