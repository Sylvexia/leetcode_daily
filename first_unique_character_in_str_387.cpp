// 387. First Unique Character in a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        array<int, 26> count = {0};

        for (int i = 0; i < s.size(); ++i)
        {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};