// 438. Find All Anagrams in a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return {};
            
        array<int, 26> count{}, cur{};

        for (int i = 0; i < 26; i++)
        {
            count[i] = 0;
            cur[i] = 0;
        }

        for (int i = 0; i < p.size(); i++)
        {
            count[p[i] - 'a']++;
            cur[s[i] - 'a']++;
        }

        vector<int> res;

        for (int i = 0; i < (s.size() - p.size()); i++)
        {
            if (cur == count)
                res.push_back(i);

            cur[s[i] - 'a']--;
            cur[s[i + p.size()] - 'a']++;
        }

        // check the last element
        if (cur == count)
            res.push_back(s.size() - p.size());

        return res;
    }
};