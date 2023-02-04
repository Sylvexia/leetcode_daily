// 212. Word Search II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    class TrieNode
    {
    public:
        array<TrieNode *, 26> next;
        bool isWord;

        TrieNode()
        {
            for (auto &ele : next)
                ele = nullptr;
            isWord = false;
        }
    };

    TrieNode *m_root = new TrieNode();

    void insert(string &word)
    {
        TrieNode *node = m_root;

        for (auto ch : word)
        {
            int curr_idx = ch - 'a';

            if (!node->next[curr_idx])
                node->next[curr_idx] = new TrieNode();

            node = node->next[curr_idx];
        }

        node->isWord = true;
    }

    void search(vector<vector<char>> &board, int i, int j, TrieNode *node, string word, vector<string> &res)
    {
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] == '#')
            return;

        char c = board[i][j];
        node = node->next[c - 'a'];
        if (!node)
            return;

        word += board[i][j];
        if (node->isWord)
        {
            res.push_back(word);
            node->isWord = false;
        }

        board[i][j] = '#';

        search(board, i + 1, j, node, word, res);
        search(board, i - 1, j, node, word, res);
        search(board, i, j + 1, node, word, res);
        search(board, i, j - 1, node, word, res);

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (auto word : words)
            insert(word);

        TrieNode *node = m_root;
        vector<string> res{};
        string word{};

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                search(board, i, j, node, word, res);
        }

        return res;
    }
};

class Solution
{
    struct TrieNode
    {
        array<TrieNode *, 26> next;
        string word;

        TrieNode()
        {
            for (auto &n : next)
                n = nullptr;
        }
    };

    inline void insert(string &word, TrieNode *root)
    {
        TrieNode *node = root;

        for (auto ch : word)
        {
            int curr_idx = ch - 'a';

            if (!node->next[curr_idx])
                node->next[curr_idx] = new TrieNode();

            node = node->next[curr_idx];
        }

        node->word = word;
    }

    void search(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &res)
    {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return;

        char c = board[i][j];
        if (c == '#' || !node->next[c - 'a'])
            return;

        node = node->next[c - 'a'];

        if (node->word.size())
        {
            res.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        search(board, i + 1, j, node, res);
        search(board, i - 1, j, node, res);
        search(board, i, j + 1, node, res);
        search(board, i, j - 1, node, res);

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (auto word : words)
            insert(word, root);

        vector<string> res;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                search(board, i, j, root, res);
        }

        return res;
    }
};