// 567. Permutation in String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        array<int, 26> count, cur;

        for (auto &ele : count)
            ele = 0;

        for (auto &ele : cur)
            ele = 0;

        for (const auto ch : s1)
            count[ch - 'a']++;

        for (int i = 0; i < s2.size(); i++)
        {
            cur[s2[i] - 'a']++;
            
            if (i >= s1.size())
                cur[s2[i - s1.size()] - 'a']--;
            if (cur == count)
                return true;
        }

        return false;
    }
};