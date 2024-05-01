// 2000. Reverse Prefix of Word

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        auto it = word.begin();
        for (; it != word.end(); it++) {
            if (*it == ch)
                break;
        }

        if (it == word.end())
            return word;

        reverse(word.begin(), it + 1);

        return word;
    }
};