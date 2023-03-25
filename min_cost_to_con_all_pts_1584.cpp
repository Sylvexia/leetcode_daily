// 1584. Min Cost to Connect All Points

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size(), cur_p = 0, connected = 1, res = 0;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<bool> visited(n, false);
        while (connected < n)
        {
            visited[cur_p] = true;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    pq.push(
                        {abs(points[i][0] - points[cur_p][0]) +
                             abs(points[i][1] - points[cur_p][1]),
                         i});
                }
            }

            while (visited[pq.top().second])
                pq.pop();

            res += pq.top().first;
            cur_p = pq.top().second;
            pq.pop();
            connected++;
        }

        return res;
    }
};