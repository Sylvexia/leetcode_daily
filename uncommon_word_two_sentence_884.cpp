// 884. Uncommon Words from Two Sentences

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> u_map;
        for (int i = 0; i < s1.size(); i++) {
            string word;
            while (s1[i] != ' ' and i < s1.size())
                word.push_back(s1[i++]);
            u_map[word]++;
        }
        for (int i = 0; i < s2.size(); i++) {
            string word;
            while (s2[i] != ' ' and i < s2.size())
                word.push_back(s2[i++]);
            u_map[word]++;
        }

        vector<string> res;
        for (auto [key, val] : u_map) {
            if (val == 1)
                res.push_back(key);
        }
        return res;
    }
};