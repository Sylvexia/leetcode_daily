// 1337. The K Weakest Rows in a Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;

            for (int j = 0; j < mat[i].size(); j++)
                count += (mat[i][j] == 1) ? 1 : 0;

            vec.push_back({count, i});
        }

        sort(vec.begin(), vec.end());

        vector<int> res(k);
        for (int i = 0; i < k; i++)
            res[i] = vec[i].second;

        return res;
    }
};