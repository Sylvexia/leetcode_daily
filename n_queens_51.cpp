// 51. N-Queens

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_set<int> cols;
    unordered_set<int> negDiags;
    unordered_set<int> posDiags;

    inline bool is_valid(const int row, const int col)
    {
        if (cols.find(col) != cols.end() or
            negDiags.find(row - col) != negDiags.end() or
            posDiags.find(row + col) != posDiags.end())
            return false;

        return true;
    }

    inline void occupy(const int row, const int col, vector<string> &board)
    {
        cols.insert(col);
        negDiags.insert(row - col);
        posDiags.insert(row + col);
        board[row][col] = 'Q';
    }

    inline void revert(const int row, const int col, vector<string> &board)
    {
        cols.erase(col);
        negDiags.erase(row - col);
        posDiags.erase(row + col);
        board[row][col] = '.';
    }

    void helper(vector<string> &board, int row, vector<vector<string>> &res)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col)
        {
            if (!is_valid(row, col))
                continue;

            occupy(row, col, board);

            helper(board, row + 1, res);

            revert(row, col, board);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;

        helper(board, 0, res);

        return res;
    }
};