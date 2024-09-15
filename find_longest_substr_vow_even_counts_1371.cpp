// 1371. Find the Longest Substring Containing Vowels in Even Counts

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<int, int> u_map{{0, -1}};
        string str_set = "aeiou";
        int mask = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            auto str_pos = str_set.find(s[i]);
            if (str_pos != string::npos)
                mask ^= 1 << str_pos;
            if (!u_map.count(mask))
                u_map[mask] = i;
            res = max(res, i - u_map[mask]);
        }
        return res;
    }
};