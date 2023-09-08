// 58. Length of Last Word

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int last_i = s.size() - 1;
        while (last_i >= 0 and s[last_i] == ' ') {
            last_i--;
        }
        if (last_i < 0)
            return 0;

        int res = 0;
        while (last_i >= 0 and s[last_i] != ' ')
        {
            last_i--;
            res++;
        }

        return res;
    }
};