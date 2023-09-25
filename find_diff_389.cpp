// 389. Find the Difference

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> u_map;
        for (char ch : s)
            u_map[ch]++;

        for (char ch : t) {
            if (u_map[ch] > 0)
                u_map[ch]--;
            else
                return ch;
        }

        return -1;
    }
};

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int arr[26];
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < s.size(); i++)
            arr[s[i] - 'a']++;

        for (int i = 0; i < t.size(); i++) {
            if (--arr[t[i] - 'a'] < 0)
                return t[i];
        }

        return '\0';
    }
};