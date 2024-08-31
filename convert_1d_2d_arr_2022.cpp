// 2022. Convert 1D Array Into 2D Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != m * n)
            return vector<vector<int>>();
        
        vector<vector<int>> res;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++)
                row.push_back(original[idx++]);
            res.push_back(row);
        }

        return res;
    }
};