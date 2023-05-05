// 1456. Maximum Number of Vowels in a Substring of Given Length

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int res = 0;
        string vowels = "aeiou";
        unordered_map<char, int> u_map;
        for (int i = 0; i < k; i++)
        {
            u_map[s[i]]++;
        }
        for (char v : vowels)
            res += u_map[v];

        for (int i = k; i < s.size(); i++)
        {
            u_map[s[i]]++;
            u_map[s[i - k]]--;

            int cur = 0;
            for (char v : vowels)
                cur += u_map[v];
            res = max(res, cur);
        }
        return res;
    }
};

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int res = 0;
        int count[26];
        string vowels = "aeiou";
        memset(count, 0, sizeof(count));
        for (int i = 0; i < k; i++)
        {
            count[s[i] - 'a']++;
        }
        for (char v : vowels)
            res += count[v - 'a'];

        for (int i = k; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            count[s[i - k] - 'a']--;

            int cur = 0;
            for (char v : vowels)
                cur += count[v - 'a'];
            res = max(res, cur);
        }
        return res;
    }
};

static const auto init = []{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        return false;
}();