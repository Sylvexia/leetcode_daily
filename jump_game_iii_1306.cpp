// 1306. Jump Game III

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionBFS
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);

        while (q.size()) {
            int front = q.front();
            q.pop();

            if (arr[front] == 0)
                return true;
            if (visited[front])
                continue;
            visited[front] = true;

            if (front + arr[front] < n)
                q.push(front + arr[front]);
            if (front - arr[front] >= 0)
                q.push(front - arr[front]);
        }
        return false;
    }
};

class Solution
{
    vector<bool> visited;

    bool dfs(int i, vector<int> &arr)
    {
        int n = arr.size();
        if (i >= n)
            return false;
        if (i < 0)
            return false;
        if (arr[i] == 0)
            return true;
        if (visited[i])
            return false;
        visited[i] = true;

        bool res = false;
        res |= dfs(i + arr[i], arr);
        res |= dfs(i - arr[i], arr);

        return res;
    }


public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        visited.resize(n, false);

        return dfs(start, arr);
    }
};