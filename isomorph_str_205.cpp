// 205. Isomorphic Strings

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        array<int, 128> s_count{};
        array<int, 128> t_count{};

        for (int i = 0; i < s.size(); i++)
        {
            if (s_count[s[i]] != t_count[t[i]])
                return false;
                
            s_count[s[i]] = i + 1;
            t_count[t[i]] = i + 1;
        }

        return true;
    }
};