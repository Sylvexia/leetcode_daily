// 1642. Furthest Building You Can Reach

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int res = 0;
        queue<tuple<int, int, int>> q;
        q.push({bricks, ladders, 0});
        while (!q.empty()) {
            auto [cur_brick, cur_ladder, cur_index] = q.front();
            q.pop();
            res = max(res, cur_index);
            if (cur_index + 1 >= heights.size())
                break;
            int brick_needed = heights[cur_index + 1] - heights[cur_index];
            if (brick_needed <= 0) {
                q.push({cur_brick, cur_ladder, cur_index + 1});
            } else {
                if (cur_brick >= brick_needed)
                    q.push(
                        {cur_brick - brick_needed, cur_ladder, cur_index + 1});
                if (cur_ladder > 0)
                    q.push({cur_brick, cur_ladder - 1, cur_index + 1});
            }
        }
        return res;
    }
};  // tle

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.push(diff);
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};