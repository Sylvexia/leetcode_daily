// 3856. Trim Trailing Vowels

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string trimTrailingVowels(string s)
    {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int i;
        for (i = n - 1; i >= 0; i--) {
            if (!vowel.count(s[i]))
                break;
        }

        return {s.begin(), s.begin() + i + 1};
    }
};