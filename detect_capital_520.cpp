// 520. Detect Capital

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        for (int i = 1; i < word.size(); i++)
        {
            if ((islower(word[0]) && isupper(word[i])) ||
                (isupper(word[1]) != isupper(word[i])))
                return false;
        }
        return true;
    }
};