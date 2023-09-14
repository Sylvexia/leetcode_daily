// 332. Reconstruct Itinerary

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        m_graph;
    vector<string> m_res;

    void dfs(string &parent)
    {
        auto &childs = m_graph[parent];
        while (!childs.empty()) {
            string top_child = childs.top();
            childs.pop();
            dfs(top_child);
        }
        m_res.push_back(parent);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto &e : tickets)
            m_graph[e[0]].push(e[1]);

        string start = "JFK";
        dfs(start);
        reverse(m_res.begin(), m_res.end());
        return m_res;
    }
};