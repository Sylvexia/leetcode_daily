// 2503. Maximum Number of Points From Grid Queries

#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    using Node = tuple<int, int, int>;
    array<int, 5> dir = {0, 1, 0, -1, 0};

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> threshes(m * n + 1);
        vector<vector<int>> minValReach(m, vector<int>(n, INT_MAX));
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({grid[0][0], 0, 0});
        int visited = 0;
        minValReach[0][0] = grid[0][0];
        while (pq.size()) {
            auto [curVal, curI, curJ] = pq.top();
            pq.pop();
            threshes[++visited] = curVal;
            for (int i = 0; i < 4; i++) {
                int newI = curI + dir[i];
                int newJ = curJ + dir[i + 1];
                if (newI < 0 or newJ < 0 or newI >= m or newJ >= n or
                    minValReach[newI][newJ] != INT_MAX)
                    continue;
                minValReach[newI][newJ] = max(curVal, grid[newI][newJ]);
                pq.push({minValReach[newI][newJ], newI, newJ});
            }
        }

        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int yes = 0;
            int no = threshes.size();
            while (abs(yes - no) > 1) {
                long long m = (yes + no) / 2;
                if (queries[i] > threshes[m])
                    yes = m;
                else
                    no = m;
            }
            res.push_back(yes);
        }
        return res;
    }
};