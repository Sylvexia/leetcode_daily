// 2924. Find Champion II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n, 0);
        for (auto e : edges)
            indegree[e[1]]++;

        int res = -1;
        int num_champ = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                num_champ++;
                res = i;
            }
        }
        return (num_champ == 1) ? res : -1;
    }
};