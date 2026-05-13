// 1351. Count Negative Numbers in a Sorted Matrix

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int res = 0;
        for (auto &r : grid) {
            for (auto c : r)
                res += c < 0;
        }
        return res;
    }
};