// 3983. Subsequence After One Replacement

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canMakeSubsequence(string s, string t)
    {
        int no_r = 0, with_r = 0;

        for (char c : t) {
            if (with_r < s.size() and s[with_r] == c)
                with_r++;

            if (no_r < s.size())
                with_r = max(with_r, no_r + 1);

            if (no_r < s.size() and s[no_r] == c)
                no_r++;

            if (no_r == s.size() or with_r == s.size())
                return true;
        }

        return no_r == s.size() or with_r == s.size();
    }
};