// 2127. Maximum Employees to Be Invited to a Meeting

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        vector<bool> visited(n);
        vector<int> indegrees(n);
        for (int i = 0; i < n; i++)
            ++indegrees[favorite[i]];

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                visited[i] = true;
                q.push(i);
            }
        }

        vector<int> dp(n);
        while (q.size()) {
            int front = q.front();
            q.pop();
            dp[favorite[front]] = max(dp[favorite[front]], dp[front] + 1);
            if (--indegrees[favorite[front]] == 0) {
                visited[favorite[front]] = true;
                q.push(favorite[front]);
            }
        }

        int res = 0;
        int res2 = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int len = 0;
            for (int j = i; !visited[j]; j = favorite[j]) {
                visited[j] = true;
                len++;
            }
            if (len == 2)
                res2 += 2 + dp[i] + dp[favorite[i]];
            else
                res = max(res, len);
        }
        return max(res, res2);
    }
};