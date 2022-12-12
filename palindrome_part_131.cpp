// 131. Palindrome Partitioning

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool is_palin(const string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void dfs(const string &s, vector<string> &gen, vector<vector<string>> &res)
    {
        if (s.size() <= 0)
            return;

        if (is_palin(s))
        {
            gen.push_back(s);
            res.push_back(gen);
            gen.pop_back();
        }

        for (int i = 1; i < s.size(); i++)
        {
            string str = s.substr(0, i);
            if (is_palin(str))
            {
                gen.push_back(str);
                dfs(s.substr(i, s.size() - i), gen, res);
                gen.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> gen;
        vector<vector<string>> res;
        dfs(s, gen, res);
        return res;
    }
};