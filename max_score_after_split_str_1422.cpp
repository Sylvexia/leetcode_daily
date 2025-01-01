// 1422. Maximum Score After Splitting a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int res = 0;
        int cur = 0;
        for (char c : s)
            cur += c == '1';
        for (int i = 0; i < s.size() - 1; i++) {
            char c = s[i];
            cur -= c == '1';
            cur += c == '0';
            res = max(res, cur);
        }
        return res;
    }
};