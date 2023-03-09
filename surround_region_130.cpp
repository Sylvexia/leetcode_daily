// 130. Surrounded Regions

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void mark_as(char mark_if, char as_ch, vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size())
            return;

        if (board[i][j] != mark_if)
            return;

        board[i][j] = as_ch;

        mark_as(mark_if, as_ch, board, i + 1, j);
        mark_as(mark_if, as_ch, board, i - 1, j);
        mark_as(mark_if, as_ch, board, i, j + 1);
        mark_as(mark_if, as_ch, board, i, j - 1);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            mark_as('O', 'N', board, i, 0);
            mark_as('O', 'N', board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            mark_as('O', 'N', board, 0, j);
            mark_as('O', 'N', board, board.size() - 1, j);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == 'N')
                    board[i][j] = 'O';
            }
        }
    }
};