// 1094. Car Pooling

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int cur = 0;
        map<int, int> u_map;
        for (auto &t : trips) {
            u_map[t[1]] += t[0];
            u_map[t[2]] -= t[0];
        }

        for (auto &[location, overlap] : u_map) {
            cur += overlap;
            if (cur > capacity)
                return false;
        }
        return true;
    }
};