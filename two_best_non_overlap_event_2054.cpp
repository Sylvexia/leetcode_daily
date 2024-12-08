// 2054. Two Best Non-Overlapping Events

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        vector<tuple<int, bool, int>> times;
        for (auto &e : events) {
            times.push_back({e[0], true, e[2]});
            times.push_back({e[1] + 1, false, e[2]});
        }

        int res = 0, curMax = 0;
        sort(times.begin(), times.end());
        for (auto [time, isStart, val] : times) {
            if (isStart)
                res = max(res, val + curMax);
            else
                curMax = max(curMax, val);
        }
        return res;
    }
};