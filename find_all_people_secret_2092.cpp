// 2092. Find All People With Secret

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findAllPeople(int n,
                              vector<vector<int>> &meetings,
                              int firstPerson)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto m : meetings) {
            graph[m[0]].push_back({m[1], m[2]});
            graph[m[1]].push_back({m[0], m[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        // (time, person)
        q.push({0, firstPerson});
        q.push({0, 0});

        vector<bool> visited(n, false);

        while (!q.empty()) {
            auto [time, person] = q.top();
            q.pop();

            if (visited[person])
                continue;

            visited[person] = true;

            for (auto [next_person, next_time] : graph[person]) {
                if (!visited[next_person] and time <= next_time)
                    q.push({next_time, next_person});
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                res.push_back(i);
        }
        return res;
    }
};