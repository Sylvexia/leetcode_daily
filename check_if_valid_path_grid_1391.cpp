// 1391. Check if There is a Valid Path in a Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool dfs(int i,
             int j,
             vector<vector<int>> &grid,
             vector<vector<bool>> &visited,
             unordered_map<int, vector<pair<int, int>>> &Map)
    {
        int m = grid.size(), n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return true;

        visited[i][j] = true;

        for (auto dir : Map[grid[i][j]]) {
            int x = i + dir.first, y = j + dir.second;
            if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
                continue;

            bool rev = false;
            for (auto d : Map[grid[x][y]]) {
                if (x + d.first == i && y + d.second == j) {
                    rev = true;
                    break;
                }
            }

            if (rev && dfs(x, y, grid, visited, Map))
                return true;
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, vector<pair<int, int>>> Map;
        Map[1] = {{0, -1}, {0, 1}};
        Map[2] = {{-1, 0}, {1, 0}};
        Map[3] = {{0, -1}, {1, 0}};
        Map[4] = {{1, 0}, {0, 1}};
        Map[5] = {{0, -1}, {-1, 0}};
        Map[6] = {{-1, 0}, {0, 1}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, grid, visited, Map);
    }
};