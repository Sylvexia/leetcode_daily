// 847. Shortest Path Visiting All Nodes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    struct Node {
        int id, mask, cost;
    };

public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();

        queue<Node> q;
        set<pair<int, int>> visit;
        int goal = (1 << n) - 1;

        for (int i = 0; i < n; i++) {
            int mask_val = (1 << i);

            q.push({i, mask_val, 1});

            visit.insert({i, mask_val});
        }

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            if (curr.mask == goal)
                return curr.cost - 1;

            for (auto &child : graph[curr.id]) {
                int curr_mask = curr.mask | (1 << child);

                if (visit.find({child, curr_mask}) == visit.end()) {
                    visit.insert({child, curr_mask});
                    q.push({child, curr_mask, curr.cost + 1});
                }
            }
        }

        return -1;
    }
};