// 2359. Find Closest Node to Given Two Nodes

#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution
{
    void dfs(int i, int depth, vector<int> &edges, vector<int> &dist)
    {
        if (edges[i] == -1)
            return;
        if (dist[edges[i]] > depth + 1) {
            dist[edges[i]] = depth + 1;
            dfs(edges[i], depth + 1, edges, dist);
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int res = -1, min_dist = INT_MAX;
        int n = edges.size();

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        dist1[node1] = 0;
        dist2[node2] = 0;
        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);

        for (int i = 0; i < n; i++) {
            if (dist1[i] != INT_MAX and dist2[i] != INT_MAX and
                max(dist1[i], dist2[i]) < min_dist) {
                res = i;
                min_dist = max(dist1[i], dist2[i]);
            }
        }
        return res;
    }
};