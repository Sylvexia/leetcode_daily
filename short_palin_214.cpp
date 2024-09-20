// 214. Shortest Palindrome

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev_str = string(s.rbegin(), s.rend());
        string concat_str = s + "#" + rev_str;
        int n = concat_str.size();
        vector<int> prefix(n);
        int len = 0;
        for (int i = 1; i < n; i++) {
            while (len > 0 and concat_str[i] != concat_str[len])
                len = prefix[len - 1];
            if (concat_str[i] == concat_str[len])
                len++;
            prefix[i] = len;
        }

        int palin_len = prefix[n - 1];
        string suffix = rev_str.substr(0, s.size() - palin_len);
        return suffix + s;
    }
};