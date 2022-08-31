// 417. Pacific Atlantic Water Flow

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int m{}, n{};
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size(), n = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        return res;
    }

    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j)
    {
        if (visited[i][j])
            return;
            
        visited[i][j] = true;

        if (atlantic[i][j] && pacific[i][j])
            res.push_back(vector<int>{i, j});

        if (i + 1 < m && mat[i + 1][j] >= mat[i][j])
            dfs(mat, visited, i + 1, j);

        if (i - 1 >= 0 && mat[i - 1][j] >= mat[i][j])
            dfs(mat, visited, i - 1, j);

        if (j + 1 < n && mat[i][j + 1] >= mat[i][j])
            dfs(mat, visited, i, j + 1);

        if (j - 1 >= 0 && mat[i][j - 1] >= mat[i][j])
            dfs(mat, visited, i, j - 1);
    }
};