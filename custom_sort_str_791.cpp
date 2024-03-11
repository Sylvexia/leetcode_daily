// 791. Custom Sort String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> count;
        for (char ch : s)
            count[ch]++;

        string res;
        for (char ch : order) {
            if (count.count(ch)) {
                for (int i = 0; i < count[ch]; i++)
                    res.push_back(ch);
                count.erase(ch);
            }
        }

        for (auto [key, value] : count) {
            for (int i = 0; i < value; i++)
                res.push_back(key);
        }

        return res;
    }
};