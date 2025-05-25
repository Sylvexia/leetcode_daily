// 2131. Longest Palindrome by Concatenating Two Letter Words

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> u_map;

        for (auto &w : words)
            u_map[w]++;

        int res = 0;
        int twin = 0;
        bool mod_1 = false;
        for (auto [key, val] : u_map) {
            string rev{key[1], key[0]};
            if (key[0] == key[1]) {
                twin += val / 2 * 4;
                mod_1 |= val % 2;
                continue;
            }
            if (u_map.count(rev)) {
                res += min(u_map[key], u_map[rev]) * 2;
            }
        }
        return res + mod_1 * 2 + twin;
    }
};