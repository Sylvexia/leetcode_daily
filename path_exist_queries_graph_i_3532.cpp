// 3532. Path Existence Queries in a Graph I

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n,
                                      vector<int> &nums,
                                      int maxDiff,
                                      vector<vector<int>> &queries)
    {
        vector<int> group(n);
        int id = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            group[i] = id;
        }

        vector<bool> res;
        for (auto &q : queries)
            res.push_back(group[q[0]] == group[q[1]]);

        return res;
    }
};