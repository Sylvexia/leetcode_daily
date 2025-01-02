// 2559. Count Vowel Strings in Ranges

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<bool> cache;
        for (auto &w : words) {
            bool isVal = vowels.count(w.front()) && vowels.count(w.back());
            cache.push_back(isVal);
        }

        vector<int> prefix(words.size(), 0);
        prefix[0] = cache[0] == true;
        for (int i = 1; i < words.size(); i++)
            prefix[i] = prefix[i - 1] + cache[i];

        vector<int> res;
        for (auto &q : queries) {
            int start = q[0], end = q[1];
            if (start == 0)
                res.push_back(prefix[end]);
            else
                res.push_back(prefix[end] - prefix[start - 1]);
        }
        return res;
    }
};