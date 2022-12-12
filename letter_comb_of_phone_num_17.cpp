// 17. Letter Combinations of a Phone Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(const string &digits, unordered_map<char, string> &map,
             const int i, string &gen, vector<string> &res)
    {
        if (i == digits.size())
        {
            res.push_back(gen);
            return;
        }
        string search = map[digits[i]];
        for (char ch : search)
        {
            gen.push_back(ch);
            dfs(digits, map, i + 1, gen, res);
            gen.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        string gen;
        vector<string> res;
        unordered_map<char, string> map =
            {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}

            };
        dfs(digits, map, 0, gen, res);
        return res;
    }
};