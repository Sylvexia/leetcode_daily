// 2661. First Completely Painted Row or Column

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int, pair<int, int>> u_map;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
                u_map[mat[i][j]] = {i, j};
        }

        unordered_map<int, int> i_map, j_map;
        for (int idx = 0; idx < arr.size(); idx++)
        {
            auto [i, j] = u_map[arr[idx]];
            i_map[i]++;
            j_map[j]++;
            if (i_map[i] == mat[0].size())
                return idx;
            if (j_map[j] == mat.size())
                return idx;
        }
        return -1;
    }
};