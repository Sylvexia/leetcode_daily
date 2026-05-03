// 3898. Find the Degree of Each Vertex

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findDegrees(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            int cur = 0;
            for (int i = 0; i < m; i++)
                cur += matrix[i][j];
            res.push_back(cur);
        }
        return res;
    }
};