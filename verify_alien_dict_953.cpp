// 953. Verifying an Alien Dictionary

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline bool compare(string &s1, string &s2, array<int, 26> order_map)
    {
        for (int i = 0; i < s1.size() && i < s2.size(); i++)
        {
            if (order_map[s1[i] - 'a'] < order_map[s2[i] - 'a'])
                return true;
            if (order_map[s1[i] - 'a'] > order_map[s2[i] - 'a'])
                return false;
        }
        
        if (s1.size() > s2.size())
            return false;

        return true;
    }

public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        array<int, 26> order_map;

        for (int i = 0; i < order.size(); i++)
            order_map[order[i] - 'a'] = i;

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!compare(words[i], words[i + 1], order_map))
                return false;
        }

        return true;
    }
};