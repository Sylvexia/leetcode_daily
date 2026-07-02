// 2608. Shortest Cycle in a Graph

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);

            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (q.size()) {
                int front = q.front();
                q.pop();
                for (int child : graph[front]) {
                    if (dist[child] == -1) {
                        dist[child] = dist[front] + 1;
                        parent[child] = front;
                        q.push(child);
                        continue;
                    }
                    // cycle found
                    if (parent[front] == child)
                        continue;
                    if (parent[child] == front)
                        continue;
                    res = min(res, dist[front] + dist[child] + 1);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};