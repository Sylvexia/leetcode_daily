// 3342. Find Minimum Time to Reach Last Room II

#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution
{
    using t4i = tuple<int, int, int, int>;

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size();
        int n = moveTime[0].size();
        int dir[5] = {0, 1, 0, -1, 0};

        priority_queue<t4i, vector<t4i>, greater<t4i>> pq;
        pq.push({0, 0, 0, 0});

        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        while (pq.size()) {
            auto [curTime, curI, curJ, alt] = pq.top();
            pq.pop();

            if (curTime > minTime[curI][curJ])
                continue;

            if (curI == m - 1 and curJ == n - 1)
                return curTime;

            for (int i = 0; i < 4; i++) {
                int newI = curI + dir[i];
                int newJ = curJ + dir[i + 1];

                if (newI < 0 or newJ < 0 or newI >= m or newJ >= n)
                    continue;

                int waitTime = max(moveTime[newI][newJ] - curTime, 0);
                int moveCost = alt % 2 == 0 ? 1 : 2;
                int nextTime = curTime + waitTime + moveCost;

                if (nextTime < minTime[newI][newJ]) {
                    minTime[newI][newJ] = nextTime;
                    pq.push({nextTime, newI, newJ, alt + 1});
                }
            }
        }
        return -1;
    }
};