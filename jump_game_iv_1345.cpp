// 1345. Jump Game IV

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < arr.size(); i++)
            graph[arr[i]].push_back(i);

        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(0), visited[0] = true;

        int res = 0;
        while (!q.empty())
        {
            for (int size = q.size(); size > 0; --size)
            {
                int front_index = q.front();
                q.pop();

                if (front_index == arr.size() - 1)
                    return res;

                vector<int> &next = graph[arr[front_index]];
                next.push_back(front_index - 1);
                next.push_back(front_index + 1);

                for (int j : next)
                {
                    if (j >= 0 and j < arr.size() and !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            res++;
        }
        return -1;
    }
};