// 1334. Find the City With the Smallest Number of Neighbors at a Threshold
// Distance

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dis(n, vector<int>(n, 10001));
        int res = 0, smallest = n;
        for (auto &e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];

        for (int i = 0; i < n; i++)
            dis[i][i] = 0;

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dis[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }
};