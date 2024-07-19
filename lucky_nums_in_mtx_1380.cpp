// 1380. Lucky Numbers in a Matrix

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        unordered_set<int> u_set;
        vector<int> res;

        for (int i = 0; i < matrix.size(); i++) {
            int local_min = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                local_min = min(local_min, matrix[i][j]);
            }
            u_set.insert(local_min);
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            int local_max = INT_MIN;
            for (int i = 0; i < matrix.size(); i++)
                local_max = max(local_max, matrix[i][j]);

            if (u_set.find(local_max) != u_set.end())
                res.push_back(local_max);
        }

        return res;
    }
};