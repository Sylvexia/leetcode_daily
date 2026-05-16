// 2351. First Letter to Appear Twice

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_set<char> u_set;
        for (char c : s) {
            if (u_set.count(c))
                return c;
            u_set.insert(c);
        }
        return '?';
    }
};