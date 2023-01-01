// 290. Word Pattern

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> char_map{};
        unordered_map<string, int> str_map{};

        istringstream in(s);
        string word;
        int i = 0, n = pattern.size();

        for (word; in >> word; i++)
        {
            if (char_map[pattern[i]] != str_map[word])
                return false;
            char_map[pattern[i]] = i + 1; // default map val is zero so use 1-index
            str_map[word] = i + 1;
        }

        return i == n;
    }
};