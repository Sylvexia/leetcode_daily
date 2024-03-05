// // 1750. Minimum Length of String After Deleting Similar Ends

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumLength(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            char cur = s[l];
            if (l == r)
                return 1;
            if (cur != s[r])
                return r - l + 1;
            while (l < s.size() and cur == s[l])
                l++;
            while (r >= 0 and cur == s[r])
                r--;
        }
        return 0;
    }
};