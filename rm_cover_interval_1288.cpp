// 1288. Remove Covered Intervals

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        auto comp = [&](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };
        ranges::sort(intervals, comp);

        int res = 0;
        int maxEnd = 0;

        for (auto &i : intervals) {
            if (i[1] > maxEnd) {
                res++;
                maxEnd = i[1];
            }
        }
        return res;
    }
};