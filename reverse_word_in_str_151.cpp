// 151. Reverse Words in a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> vec;
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            word.clear();
            while (i < s.size() and s[i] == ' ')
                i++;

            while (i < s.size() and s[i] != ' ')
            {
                word.push_back(s[i]);
                i++;
            }
            if (word.size())
                vec.push_back(word);
        }

        string res;

        while (vec.size())
        {
            res.append(vec.back());
            res.append(" ");
            vec.pop_back();
        }

        if (res.size() and res.back() == ' ')
            res.pop_back();

        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseWords("  hello world  ");
}