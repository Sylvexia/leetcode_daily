// 383. Ransom Note

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        array<int, 26> ran_count{};
        array<int, 26> mag_count{};

        for (int i = 0; i < ransomNote.size(); i++)
            ran_count[ransomNote[i] - 'a']++;

        for (int j = 0; j < magazine.size(); j++)
            mag_count[magazine[j] - 'a']++;

        for (int k = 0; k < 26; k++)
        {
            if (ran_count[k] > mag_count[k])
                return false;
        }

        return true;
    }
};
// aab, aabb
// bc, d