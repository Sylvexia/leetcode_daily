#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        for (int i = 0, j = 0;
             i < word1.size() or j < word2.size();
             i++, j++)
        {
            if (i < word1.size())
                res.push_back(word1[i]);
            if (j < word2.size())
                res.push_back(word2[i]);
        }
        return res;
    }
};