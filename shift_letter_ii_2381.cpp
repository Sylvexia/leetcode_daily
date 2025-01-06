// 2381. Shifting Letters II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        map<int, int> mp;
        for (auto &s : shifts) {
            if (s[2]) {
                mp[s[0]]++;
                mp[s[1] + 1]--;
            } else {
                mp[s[0]]--;
                mp[s[1] + 1]++;
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += mp[i];
            int num = s[i] - 'a' + cur;
            if (num < 0)
                num = (26 - (-num % 26)) % 26;
            else
                num %= 26;
            s[i] = num + 'a';
        }

        return s;
    }
};