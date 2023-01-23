// 997. Find the Town Judge

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int count[n + 1];
        memset(count, 0, sizeof(count));

        for (auto pair : trust)
            count[pair[0]]--, count[pair[1]]++;

        for (int i = 1; i <= n; ++i)
        {
            if (count[i] == n - 1)
                return i;
        }

        return -1;
    }
};