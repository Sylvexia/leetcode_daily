// 1910. Remove All Occurrences of a Substring

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string res;
        int n = part.size();
        for (char ch : s) {
            res.push_back(ch);
            while (res.size() >= n and res.substr(res.size() - n) == part) {
                for (int i = 0; i < n; i++)
                    res.pop_back();
            }
        }
        return res;
    }
};