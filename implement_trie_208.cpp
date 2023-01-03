// 208. Implement Trie (Prefix Tree)

#include <bits/stdc++.h>

using namespace std;

class Trie
{
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool isWord;
        TrieNode()
        {
            isWord = false;
            for (auto &alphabet : next)
                alphabet = nullptr;
        }
    };

    TrieNode *root;

    TrieNode *find(string word)
    {
        TrieNode *p = root;
        for (auto ch : word)
        {
            p = p->next[ch - 'a'];
            if (!p)
                break;
        }
        return p;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *p = root;
        for (auto ch : word)
        {
            if (!(p->next[ch - 'a']))
                p->next[ch - 'a'] = new TrieNode;
            p = p->next[ch - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *p = find(word);
        return p && p->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *p = find(prefix);
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */