// 54. Spiral Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), count = 0, total = m * n;
        vector<int> ret(m * n, -101);

        int i = 0, j = 0;
        int i_step = 0, j_step = 1;

        while (count < total)
        {
            ret[count] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            count++;

            if (i_step == 1 && (i == m - 1 || matrix[i + 1][j] == INT_MAX))
            {
                i_step = 0;
                j_step = -1;
            }
            else if (i_step == -1 && (i == 0 || matrix[i - 1][j] == INT_MAX))
            {
                i_step = 0;
                j_step = 1;
            }
            else if (j_step == 1 && (j == n - 1 || matrix[i][j + 1] == INT_MAX))
            {
                i_step = 1;
                j_step = 0;
            }
            else if (j_step == -1 && (j == 0 || matrix[i][j - 1] == INT_MAX))
            {
                i_step = -1;
                j_step = 0;
            }

            i += i_step;
            j += j_step;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vec;
    int count = 0;

    cout << "meow";

    for (int i = 0; i < 4; i++)
    {
        vector<int> row;
        for (int j = 0; j < 3; j++)
        {
            row.push_back(count);
            count++;
        }
        vec.push_back(row);
    }

    sol.spiralOrder(vec);
    return 0;
}