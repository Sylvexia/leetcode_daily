// 3341. Find Minimum Time to Reach Last Room I

#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

class Solution
{
    using tiii = tuple<int, int, int>;

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        pq.push({0, 0, 0});

        int dir[5] = {0, -1, 0, 1, 0};

        while (pq.size()) {
            auto [curTime, curI, curJ] = pq.top();
            pq.pop();

            if (curTime >= dp[curI][curJ])
                continue;
            if (curI == m - 1 and curJ == n - 1)
                return curTime;

            dp[curI][curJ] = curTime;

            for (int i = 0; i < 4; i++) {
                int newI = curI + dir[i];
                int newJ = curJ + dir[i + 1];
                if (newI < 0 or newJ < 0 or newI >= m or newJ >= n)
                    continue;
                if (dp[newI][newJ] != INT_MAX)
                    continue;
                int newTime = max(curTime, moveTime[newI][newJ]) + 1;
                pq.push({newTime, newI, newJ});
            }
        }
        return -1;
    }
};