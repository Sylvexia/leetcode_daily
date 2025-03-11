// 1358. Number of Substrings Containing All Three Characters

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int l = 0;
        int r = 0;
        int res = 0;
        unordered_map<char, int> u_set;
        for (; r < n; r++) {
            u_set[s[r]]++;
            for (; u_set.size() == 3; l++) {
                res += n - r;
                if (--u_set[s[l]] == 0)
                    u_set.erase(s[l]);
            }
        }
        return res;
    }
};