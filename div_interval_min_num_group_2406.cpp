// 2406. Divide Intervals Into Minimum Number of Groups

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        map<int, int> time_count;
        for (auto &i : intervals) {
            time_count[i[0]]++;
            time_count[i[1] + 1]--;
        }

        int res = 0, cur = 0;
        for (auto [time, count] : time_count) {
            cur += count;
            res = max(res, cur);
        }
        return res;
    }
};