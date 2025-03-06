// 2965. Find Missing and Repeated Values

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int nsquare = n * n;
        unordered_map<int, int> u_map;

        for (auto &r : grid) {
            for (auto c : r)
                u_map[c]++;
        }

        vector<int> res(2);
        for (int i = 1; i <= nsquare; i++) {
            if (!u_map.count(i))
                res[1] = i;
            if (u_map[i] == 2)
                res[0] = i;
        }

        return res;
    }
};