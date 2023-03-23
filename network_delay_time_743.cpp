// 743. Network Delay Time

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int max_val = 1000000;
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const auto &t : times)
            graph[t[0]].push_back({t[1], t[2]});

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        vector<int> dist(n + 1, max_val);
        dist[0] = 0, dist[k] = 0;

        pq.push({0, k});
        while (!pq.empty())
        {
            const auto [front_dist, front_node] = pq.top();
            pq.pop();

            for (auto &[ch_node, ch_dist] : graph[front_node])
            {
                if (ch_dist + front_dist < dist[ch_node])
                {
                    dist[ch_node] = ch_dist + front_dist;
                    pq.push({dist[ch_node], ch_node});
                }
            }
        }

        int res = *max_element(dist.begin(), dist.end());
        return (res == max_val) ? -1 : res;
    }
};