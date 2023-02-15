// 59. Spiral Matrix II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int count = 1, target = n * n, i = 0, j = 0, dir_index = 0;

        while (count <= target)
        {
            res[i][j] = count;

            int temp_i = i + dir[dir_index].first;
            int temp_j = j + dir[dir_index].second;

            if (temp_i < 0 or temp_i >= n or
                temp_j < 0 or temp_j >= n or
                res[temp_i][temp_j] != 0)
            {
                dir_index += 1;
                dir_index %= 4;
                i = i + dir[dir_index].first;
                j = j + dir[dir_index].second;
            }
            else
            {
                i = temp_i;
                j = temp_j;
            }

            count++;
        }

        return res;
    }
};