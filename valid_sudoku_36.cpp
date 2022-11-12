// 36. Valid Sudoku

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    array<array<bool, 9>, 9>row;
    array<array<bool, 9>, 9>col;
    array<array<bool, 9>, 9>box;

    void init(array<array<bool, 9>, 9> &array)
    {
        for(auto i: array)
        {
            for(auto j:i)
                j=false;
        }
    }

    bool isValid(int i, int j, int num)
    {
        if( row[num][i]||
            col[num][j]||
            box[num][(i/3)*3+j/3]
        )
            return false;

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        init(row);
        init(col);
        init(box);

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    continue;
                    
                int num = board[i][j] - '1';

                if(!isValid(i,j,num))
                    return false;

                row[num][i]=true;
                col[num][j]=true;
                box[num][(i/3)*3+j/3]=true;
            }
        }

        return true;    
    }
};