// 1572. Matrix Diagonal Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int res = 0;
        for (int i = 0; i < mat.size(); i++)
            res += mat[i][i];

        for (int i = 0, j = mat.size() - 1; i < mat.size(); i++, j--)
            res += mat[i][j];

        if (mat.size() % 2 == 1)
        {
            int mid = mat.size() / 2;
            res -= mat[mid][mid];
        }

        return res;
    }
};