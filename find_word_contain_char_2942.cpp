// 2942. Find Words Containing Character

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                if (ch == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};