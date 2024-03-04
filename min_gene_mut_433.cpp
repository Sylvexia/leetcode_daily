// 433. Minimum Genetic Mutation

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        bank.push_back(startGene);
        int n = bank.size();
        vector<vector<int>> graph(n);
        int start = -1, end = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diff = 0;
                for (int ch = 0; ch < 8; ch++) {
                    diff += (bank[i][ch] != bank[j][ch]);
                }
                if (diff == 1)
                    graph[i].push_back(j);
            }
            if (startGene == bank[i])
                start = i;
            if (endGene == bank[i])
                end = i;
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int res = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int front = q.front();
                q.pop();
                if (front == end)
                    return res;
                for (int child : graph[front]) {
                    if (visited[child])
                        continue;
                    q.push(child);
                    visited[child] = true;
                }
            }
            res++;
        }
        return -1;
    }
};