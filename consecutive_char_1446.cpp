// 1446. Consecutive Characters

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxPower(string s)
    {
        int res = 1;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
        return res;
    }
};