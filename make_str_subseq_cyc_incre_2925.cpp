// 2825. Make String a Subsequence Using Cyclic Increments

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int j = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[j] or
                ((str1[i] + 1 - 'a') % 26 + 'a') == str2[j])
                j++;
            if (j == str2.size())
                return true;
        }
        return false;
    }
};