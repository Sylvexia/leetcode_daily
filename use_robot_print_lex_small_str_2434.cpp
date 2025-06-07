// 2434. Using a Robot to Print the Lexicographically Smallest String

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string robotWithString(string s)
    {
        unordered_map<char, int> uMap;
        for (char c : s)
            uMap[c]++;

        string t, res;
        char curChar = 'a';

        for (char c : s) {
            t.push_back(c);
            uMap[c]--;
            while (curChar != 'z' and uMap[curChar] == 0)
                curChar++;
            while (t.size() and t.back() <= curChar) {
                res.push_back(t.back());
                t.pop_back();
            }
        }
        return res;
    }
};