// 2045. Second Minimum Time to Reach Destination

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);

        q.push({1, 1});
        dist1[1] = 0;

        while (q.size()) {
            auto [node, freq] = q.front();
            q.pop();

            int time_taken = freq == 1 ? dist1[node] : dist2[node];

            if ((time_taken / change) % 2)
                time_taken = change * (time_taken / change + 1) + time;
            else
                time_taken = time_taken + time;

            for (auto &neighbor : adj[node]) {
                if (dist1[neighbor] == -1) {
                    dist1[neighbor] = time_taken;
                    q.push({neighbor, 1});
                } else if (dist2[neighbor] == -1 and
                           dist1[neighbor] != time_taken) {
                    if (neighbor == n)
                        return time_taken;
                    dist2[neighbor] = time_taken;
                    q.push({neighbor, 2});
                }
            }
        }
        return 0;
    }
};