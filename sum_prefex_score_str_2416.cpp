// 2416. Sum of Prefix Scores of Strings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

struct TrieNode {
    TrieNode *next[26] = {};
    int cnt = 0;
};
class Solution
{
    TrieNode root;
    void insert(string &word)
    {
        TrieNode *node = &root;
        for (char c : word) {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new TrieNode();
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }
    int count(string &word)
    {
        int res = 0;
        TrieNode *node = &root;

        for (char c : word) {
            res += node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return res;
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        for (auto word : words)
            insert(word);

        vector<int> res(words.size());
        for (int i = 0; i < words.size(); i++)
            res[i] = count(words[i]);
        return res;
    }
};