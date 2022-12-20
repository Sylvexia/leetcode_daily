// 841. Keys and Rooms

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        queue<int> todo;

        todo.push(0);
        while (!todo.empty())
        {
            int top = todo.front();
            todo.pop();
            visited[top] = true;
            for (auto ele : rooms[top])
            {
                if (!visited[ele])
                    todo.push(ele);
            }
        }

        for (auto ele : visited)
        {
            if (!ele)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data = {{2, 3}, {}, {2}, {1, 3}};
    cout << sol.canVisitAllRooms(data);
}