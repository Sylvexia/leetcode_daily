// 1462. Course Schedule IV

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries)
    {
        vector<bool> res;
        vector<vector<int>> graph(n);
        vector<vector<bool>> table(n, vector<bool>(n, false));
        vector<int> indegree(n, 0);
        for (auto &p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (int child : graph[cur]) {
                table[cur][child] = true;
                for (int i = 0; i < n; i++) {
                    if (table[i][cur])
                        table[i][child] = true;
                }
                indegree[child]--;
                if (indegree[child] == 0)
                    q.push(child);
            }
        }
        for (auto &q : queries)
            res.push_back(table[q[0]][q[1]]);
        return res;
    }
};