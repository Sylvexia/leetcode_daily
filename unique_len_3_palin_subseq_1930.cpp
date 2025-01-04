// 1930. Unique Length-3 Palindromic Subsequences

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        array<int, 26> start, end;
        for (int i = 0; i < 26; i++)
            start[i] = -1, end[i] = -1;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            end[s[i] - 'a'] = i;
            start[s[n - i - 1] - 'a'] = n - i - 1;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (start[i] == -1 || end[i] == -1)
                continue;
            bitset<26> bset;
            for (int j = start[i] + 1; j < end[i]; j++)
                bset[s[j] - 'a'] = true;
            res += bset.count();
        }
        return res;
    }
};