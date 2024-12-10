// 2982. Find Longest Special Substring That Occurs Thrice II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));
        char prevChar = s[0];
        int curLeng = 1;
        freq[s[0] - 'a'][1] = 1;
        int res = -1;

        for (int i = 1; i < n; i++) {
            char curChar = s[i];
            if (curChar == prevChar) {
                curLeng++;
                freq[curChar - 'a'][curLeng]++;
            } else {
                prevChar = curChar;
                curLeng = 1;
                freq[prevChar - 'a'][1]++;
            }
        }

        for (auto &f : freq) {
            for (int len = n - 1; len >= 1; len--) {
                f[len] += f[len + 1];
                if (f[len] >= 3) {
                    res = max(res, len);
                    break;
                }
            }
        }
        return res;
    }
};