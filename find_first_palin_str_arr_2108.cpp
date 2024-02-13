// 2108. Find First Palindromic String in the Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &str : words) {
            bool isVal = true;
            for (int i = 0; i < str.size() / 2; i++) {
                if (str[i] != str[str.size() - 1 - i]) {
                    isVal = false;
                    break;
                }
            }
            if (isVal)
                return str;
        }
        return "";
    }
};