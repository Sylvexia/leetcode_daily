// 1461. Check If a String Contains All Binary Codes of Size K

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int need = 1 << k;
        vector<bool> seen(need);
        int mask = need - 1;
        int cur = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            int bit = s[i] - '0';
            cur = ((cur << 1) & mask) | bit;
            if (i >= k - 1 and !seen[cur]) {
                seen[cur] = true;
                cnt++;

                if (cnt == need)
                    return true;
            }
        }
        return false;
    }
};