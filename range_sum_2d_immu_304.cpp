// 304. Range Sum Query 2D - Immutable

#include <bits/stdc++.h>

using namespace std;

class NumMatrix
{
    vector<vector<int>> nums;

public:
    NumMatrix(vector<vector<int>> &matrix)
        : nums(matrix.size() + 1,
               vector<int>(matrix[0].size() + 1, 0))
    {
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                nums[i][j] = matrix[i - 1][j - 1] +
                             nums[i - 1][j] +
                             nums[i][j - 1] -
                             nums[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return nums[row2 + 1][col2 + 1] -
               nums[row2 + 1][col1] -
               nums[row1][col2 + 1] +
               nums[row1][col1];
    }
};