// 79. Word Search

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool dfs(vector<vector<char>> &board, const string &word, const int i, const int j, const int n)
    {
        if (n == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[n] != board[i][j])
            return false;

        board[i][j] = '0';

        bool ret = dfs(board, word, i + 1, j, n + 1) ||
                   dfs(board, word, i - 1, j, n + 1) ||
                   dfs(board, word, i, j + 1, n + 1) ||
                   dfs(board, word, i, j - 1, n + 1);

        board[i][j] = word[n];

        return ret;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j] && dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};