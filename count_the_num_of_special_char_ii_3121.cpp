// 3121. Count the Number of Special Characters II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        bitset<26> lo, hi;
        for (char ch : word) {
            if (islower(ch))
                lo[ch - 'a'] = !hi[ch - 'a'];
            else
                hi[ch - 'A'] = true;
        }
        return (lo & hi).count();
    }
};