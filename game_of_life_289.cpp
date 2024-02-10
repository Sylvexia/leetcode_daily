// 289. Game of Life

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                                       {1, 0},   {-1, 1}, {0, 1},  {1, 1}};
        vector<vector<int>> temp_board = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = 0;
                for (auto d : dirs) {
                    auto [di, dj] = d;
                    int ti = di + i;
                    int tj = dj + j;

                    if (ti < 0 or ti >= m or tj < 0 or tj >= n)
                        continue;

                    lives += (board[ti][tj] == 1);
                }
                if (!board[i][j] and lives == 3) {
                    temp_board[i][j] = 1;
                    continue;
                }
                if (board[i][j] and !(lives == 2 or lives == 3)) {
                    temp_board[i][j] = 0;
                    continue;
                }
            }
        }
        board = temp_board;
        return;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol.gameOfLife(data);
}