// 2033. Minimum Operations to Make a Uni-Value Grid

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> vec;
        for (auto &r : grid) {
            for (auto c : r)
                vec.push_back(c);
        }

        sort(vec.begin(), vec.end());
        for (int val : vec) {
            if (abs(val - vec[0]) % x != 0)
                return -1;
        }

        int n = vec.size();
        int m = vec[n / 2];
        int res = 0;

        for (int val : vec)
            res += abs(val - m) / x;
        return res;
    }
};