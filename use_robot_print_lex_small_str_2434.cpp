// 2434. Using a Robot to Print the Lexicographically Smallest String

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// 3 8 1 6 5 4 7 2 1 9

// 3 8 6 5 4 7 2  
// 1 1

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