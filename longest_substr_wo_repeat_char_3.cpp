// 3. Longest Substring Without Repeating Characters

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = -1, res = 0;

        array<int, 128> dict;
        fill(dict.begin(), dict.end(), -1);

        for (int i = 0; i < s.size(); i++)
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];

            dict[s[i]] = i;
            res = max(res, i - start);
        }

        return res;
    }
};