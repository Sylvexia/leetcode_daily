// 74. Search a 2D Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0, right = matrix.size() * matrix[0].size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int m = mid / matrix[0].size();
            int n = mid % matrix[0].size();
            if (target == matrix[m][n])
                return true;
            if (target < matrix[m][n])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};