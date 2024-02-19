// 1926. Nearest Exit from Entrance in Maze

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool is_bound(int i, int j, int m, int n)
    {
        return (i == 0 or j == 0 or i == m - 1 or j == n - 1);
    }

    bool is_val(int i, int j, int m, int n)
    {
        return i >= 0 and i < m and j >= 0 and j < n;
    }

public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        int res = 0;
        int dir[5] = {1, 0, -1, 0, 1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                auto [cur_i, cur_j] = q.front();
                q.pop();
                if (is_bound(cur_i, cur_j, m, n) and
                    !(cur_i == entrance[0] and cur_j == entrance[1]))
                    return res == 0 ? -1 : res;

                for (int i = 0; i < 4; i++) {
                    int next_i = cur_i + dir[i];
                    int next_j = cur_j + dir[i + 1];

                    if (!is_val(next_i, next_j, m, n))
                        continue;

                    if (maze[next_i][next_j] == '.' and
                        !visited[next_i][next_j]) {
                        q.push({next_i, next_j});
                        visited[next_i][next_j] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> maze{
        {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> ent{1, 2};
    int res = sol.nearestExit(maze, ent);
    cout << "res: " << res;
}