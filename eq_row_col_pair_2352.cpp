// 2352. Equal Row and Column Pairs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        unordered_map<string, int> row_count, col_count;
        for (int i = 0; i < grid.size(); i++) {
            string str;
            for (int j = 0; j < grid[0].size(); j++)
            {
                str.append(to_string(grid[i][j]));
                str.push_back(',');
            }
            row_count[str]++;
        }

        for (int j = 0; j < grid[0].size(); j++) {
            string str;
            for (int i = 0; i < grid.size(); i++)
            {
                str.append(to_string(grid[i][j]));
                str.push_back(',');
            }
            col_count[str]++;
        }

        int res = 0;
        for (auto [key, val] : row_count) {
            if (col_count.count(key))
                res += val * col_count[key];
        }

        return res;
    }
};