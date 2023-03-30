// 87. Scramble String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_set<string> visited;

    bool dfs(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1 == s2)
            return true;

        if (s1.size() <= 1)
            return false;

        string combine = s1 + s2;

        if (visited.find(combine) != visited.end())
            return false;

        int n = s1.size();

        for (int i = 1; i < n; i++)
        {
            if (dfs(s1.substr(0, i), s2.substr(0, i)) and
                dfs(s1.substr(i), s2.substr(i)))
                return true;

            if (dfs(s1.substr(0, i), s2.substr(n - i)) and
                dfs(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        visited.insert(combine);
        return false;
    }

public:
    bool isScramble(string s1, string s2)
    {
        return dfs(s1, s2);
    }
};