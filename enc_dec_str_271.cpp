// 271. Encode and Decode strings

// lint: 659

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    string encode(vector<string> &strs)
    {
        string ret;
        for (const auto &str : strs)
        {
            ret += str;
            ret += ';';
        }
        return ret;
    }

    vector<string> decode(string &str)
    {
        vector<string> ret;
        string temp;
        for (auto ch : str)
        {
            if (ch == ';')
            {
                ret.push_back(temp);
                temp.erase();
                continue;
            }
            temp += ch;
        }
        return ret;
    }
};