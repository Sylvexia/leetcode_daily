// 409. Longest Palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> u_map;

        for (auto ch : s)
            u_map[ch]++;

        int res = 0;
        bool has_odd = false;
        for (auto &[k, v] : u_map)
        {
            if (v % 2 == 1)
                has_odd = true;
            res += (v / 2) * 2;
        }

        return res + has_odd;
    }
};