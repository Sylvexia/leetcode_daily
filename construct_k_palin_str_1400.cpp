// 1400. Construct K Palindrome Strings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        array<int, 26> freq;
        fill(freq.begin(), freq.end(), 0);

        for (char ch : s)
            freq[ch - 'a']++;

        int odds = 0;
        for (int cnt : freq)
            odds += (cnt & 1);

        return k >= odds && s.size() >= k;
    }
};