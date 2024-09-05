// 1684. Count the Number of Consistent Strings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> u_set(allowed.begin(), allowed.end());

        int res = 0;
        for (string &w : words) {
            bool local = true;
            for (char ch : w) {
                if (u_set.find(ch) == u_set.end()) {
                    local = false;
                    break;
                }
            }
            res += local;
        }
        return res;
    }
};