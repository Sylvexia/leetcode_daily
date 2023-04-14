// 733. Flood Fill

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int orin_c = image[sr][sc];
        array<pair<int, int>, 4> dirs = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
        vector<vector<bool>> visited(image.size(),
                                     vector<bool>(image[0].size(), false));

        while (q.size())
        {
            auto [fi, fj] = q.front();
            q.pop();
            image[fi][fj] = color;
            visited[fi][fj] = true;

            for (const auto &[di, dj] : dirs)
            {
                const auto [ti, tj] = make_pair(fi + di, fj + dj);

                if (ti < 0 or ti >= image.size() or
                    tj < 0 or tj >= image[0].size())
                    continue;

                if (image[ti][tj] == orin_c and !visited[ti][tj])
                    q.push({ti, tj});
            }
        }

        return image;
    }
};