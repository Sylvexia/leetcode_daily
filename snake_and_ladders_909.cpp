// 909. Snakes and Ladders
#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        int target = m * n;
        vector<int> flat_vec{0};
        int row_count = 0;
        int num = 1;
        for (int i = m - 1; i >= 0; i--) {
            if (row_count % 2 == 0) {
                for (int j = 0; j < n; j++)
                    flat_vec.push_back(board[i][j] == -1 ? num : board[i][j]),
                        num++;
            } else {
                for (int j = n - 1; j >= 0; j--)
                    flat_vec.push_back(board[i][j] == -1 ? num : board[i][j]),
                        num++;
            }
            row_count++;
        }

        vector<bool> visited(target + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int res = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int front = q.front();
                q.pop();
                if (front == target)
                    return res;

                for (int i = 1; i <= 6; i++) {
                    int next = front + i;
                    if (next > target or visited[next])
                        continue;
                    q.push(flat_vec[next]);
                    visited[next] = true;
                }
            }
            res++;
        }
        return -1;
    }
};