// 2185. Counting Words With a Given Prefix

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int res = 0;
        for (auto &w : words) {
            bool cur = true;
            for (int i = 0; i < pref.size(); i++) {
                if (pref[i] != w[i]) {
                    cur = false;
                    break;
                }
            }
            res += cur;
        }
        return res;
    }
};