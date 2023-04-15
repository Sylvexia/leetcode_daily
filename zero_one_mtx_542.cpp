// 542. 01 Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }

        array<int, 5> dir{0, 1, 0, -1, 0};
        while (!q.empty())
        {
            auto [fi, fj] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ti = dir[i] + fi;
                int tj = dir[i + 1] + fj;

                if (ti < 0 or tj < 0 or
                    ti >= mat.size() or tj >= mat[0].size() or
                    mat[ti][tj] != -1)
                    continue;

                mat[ti][tj] = mat[fi][fj] + 1;
                q.push({ti, tj});
            }
        }

        return mat;
    }
};