// 2730. Find the Longest Semi-Repetitive Substring

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int n = s.size();
        int l = 0;
        int res = 1;
        int cnt = 0;
        for (int r = 1; r < n; r++) {
            cnt += (s[r] == s[r - 1]);
            for (; cnt > 1; l++) {
                if (s[l] == s[l + 1])
                    cnt--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};