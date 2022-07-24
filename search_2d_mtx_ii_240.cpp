#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix[0].size();
        int n = matrix.size();

        int i = m - 1;
        int j = 0;

        while (i >= 0 && j < n)
        {
            if (matrix[j][i] == target)
                return true;

            else if (matrix[j][i] > target)
                i--;

            else
                j++;
        }

        return false;
    }
};