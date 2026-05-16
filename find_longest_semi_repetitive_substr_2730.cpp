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
        int r{};
        int res{0};
        int cnt{0};
        for (int l = 0; l < n; l++) {
            for (; r < n and cnt <= 1; r++) {
                if (r > 0 and s[r] == s[r - 1])
                    cnt++;
                if (cnt > 1)
                    break;
            }
            res = max(res, r - l);
            if (l + 1 < n and s[l] == s[l + 1])
                cnt--;
        }
        return res;
    }
};