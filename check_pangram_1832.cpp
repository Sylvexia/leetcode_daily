// 1832. Check if the Sentence Is Pangram

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        array<int, 26> count{};
        for (auto &ele : count)
            ele = 0;

        for (auto ch : sentence)
            count[ch - 'a']++;

        for (auto ele : count)
        {
            if (ele == 0)
                return false;
        }

        return true;
    }
};