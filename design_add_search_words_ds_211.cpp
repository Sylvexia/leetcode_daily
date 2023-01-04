// 211. Design Add and Search Words Data Structure

#include <bits/stdc++.h>

using namespace std;

class WordDictionary
{
    class TrieNode
    {
    public:
        array<TrieNode *, 26> next;
        bool is_word;
        TrieNode() : is_word{false}
        {
            for (auto &ele : next)
                ele = nullptr;
        }
    };

    TrieNode *root;
    size_t max_len;

    bool search_helper(string word, TrieNode *node)
    {
        if (word.size() > max_len)
            return false;
            
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (node->next[j] &&
                        search_helper(word.substr(i + 1), node->next[j]))
                        return true;
                }
                return false;
            }
            else
            {
                if (!node->next[c - 'a'])
                    return false;
                node = node->next[c - 'a'];
            }
        }

        return node->is_word;
    }

public:
    WordDictionary() : max_len{0}
    {
        root = new TrieNode;
    }

    void addWord(string word)
    {
        TrieNode *temp = root;

        for (auto ch : word)
        {
            if (!temp->next[ch - 'a'])
                temp->next[ch - 'a'] = new TrieNode;
            temp = temp->next[ch - 'a'];
        }
        temp->is_word = true;
        max_len = max(max_len, word.size());
    }

    bool search(string word)
    {
        return search_helper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */