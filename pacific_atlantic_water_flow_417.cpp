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

class Solution2
{
public:
    void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &heights)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (q.size())
        {
            auto [row, col] = q.front();
            q.pop();
            if (visited[row][col])
                continue;
            visited[row][col] = true;

            if (row + 1 < heights.size() && heights[row][col] <= heights[row + 1][col])
                q.push({row + 1, col});
            if (row - 1 >= 0 && heights[row][col] <= heights[row - 1][col])
                q.push({row - 1, col});
            if (col + 1 < heights[0].size() && heights[row][col] <= heights[row][col + 1])
                q.push({row, col + 1});
            if (col - 1 >= 0 && heights[row][col] <= heights[row][col - 1])
                q.push({row, col - 1});
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)),
            atlantic(m, vector<bool>(n, false));

        vector<vector<int>> res;

        for (int i = 0; i < m; i++)
            bfs(i, 0, pacific, heights);
        for (int j = 0; j < n; j++)
            bfs(0, j, pacific, heights);

        for (int i = m - 1; i >= 0; i--)
            bfs(i, n - 1, atlantic, heights);
        for (int j = n - 1; j >= 0; j--)
            bfs(m - 1, j, atlantic, heights);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};

int main()
{
    Solution2 sol;
    vector<vector<int>> data{
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    vector<vector<int>> res = sol.pacificAtlantic(data);

    for (auto ele : res)
    {
        cout << ele[0] << " " << ele[1] << "\n";
    }
}