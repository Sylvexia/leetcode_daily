// 3975. Filter Occupied Intervals

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>> &occupiedIntervals,
        int freeStart,
        int freeEnd)
    {
        ranges::sort(occupiedIntervals);

        vector<vector<int>> merged;

        for (auto &i : occupiedIntervals) {
            int start = i[0];
            int end = i[1];

            if (merged.empty())
                merged.push_back({start, end});
            else {
                int lastEnd = merged.back()[1];

                if (start <= lastEnd + 1) {
                    merged.back()[1] = max(merged.back()[1], end);
                } else {
                    merged.push_back({start, end});
                }
            }
        }

        vector<vector<int>> res;
        for (auto &i : merged) {
            int l = i[0];
            int r = i[1];

            if (r < freeStart or l > freeEnd)
                res.push_back({l, r});
            else {
                if (l < freeStart) {
                    res.push_back({l, freeStart - 1});
                }

                if (r > freeEnd) {
                    res.push_back({freeEnd + 1, r});
                }
            }
        }
        return res;
    }
};