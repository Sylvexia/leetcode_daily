// 207. Course Schedule

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void build_graph(const vector<vector<int>> &prerequisites,
                     vector<vector<int>> &graph)
    {
        for (auto ele : prerequisites)
            graph[ele[1]].push_back(ele[0]);
    }

    bool is_cycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &done, int start)
    {
        if (visited[start])
            return true;
            
        if (done[start])
            return false;

        done[start] = true;

        visited[start] = true;
        for (auto ele : graph[start])
        {
            if (is_cycle(graph, visited, done, ele))
                return true;
        }
        visited[start] = false;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> done(numCourses, false);
        vector<bool> visited(numCourses, false);
        build_graph(prerequisites, graph);

        for (int i = 0; i < numCourses; i++)
        {
            if (is_cycle(graph, visited, done, i))
                return false;
        }

        return true;
    }
};