// 1631. Path With Minimum Effort

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    struct Node {
        int effort;
        int x;
        int y;
    };

    struct NodeCompare {
        inline bool operator()(const Node &n1, const Node &n2)
        {
            return (n1.effort > n2.effort);
        }
    };

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int max_y = heights.size(), max_x = heights[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> efforts(max_y, vector<int>(max_x, INT_MAX));
        priority_queue<Node, vector<Node>, NodeCompare> pq;

        efforts[0][0] = 0;
        pq.push(Node{0, 0, 0});

        while (!pq.empty()) {
            int effort = pq.top().effort;
            int x = pq.top().x;
            int y = pq.top().y;

            pq.pop();

            if (x == max_x - 1 and y == max_y - 1)
                return effort;

            for (int i = 0; i < 4; i++) {
                int new_x = dirs[i] + x;
                int new_y = dirs[i + 1] + y;

                if (new_x < 0 or new_x >= max_x or new_y < 0 or new_y >= max_y)
                    continue;

                int new_effort =
                    max(effort, abs(heights[new_y][new_x] - heights[y][x]));

                if (new_effort < efforts[new_y][new_x]) {
                    efforts[new_y][new_x] = new_effort;
                    pq.push({.effort = new_effort, .x = new_x, .y = new_y});
                }
            }
        }

        return efforts[max_y - 1][max_x - 1];
    }
};