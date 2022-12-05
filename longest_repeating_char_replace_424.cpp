// 424. Longest Repeating Character Replacement

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int max_freq = 0, res = 0;
        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++)
        {
            max_freq = max(max_freq, ++count[s[i]]);
            if (res - max_freq < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
};