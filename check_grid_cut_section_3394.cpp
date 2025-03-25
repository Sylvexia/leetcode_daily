// 3394. Check if Grid can be Cut into Sections

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool val(map<int, int> &map)
    {
        int gap = 0;
        int intersect = 0;

        for (auto &[val, count] : map) {
            intersect += count;
            gap += (intersect == 0);

            if (gap == 3)
                return true;
        }
        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        map<int, int> sweepX, sweepY;

        for (auto &r : rectangles) {
            sweepX[r[0] + 1]++;
            sweepX[r[2]]--;
            sweepY[r[1] + 1]++;
            sweepY[r[3]]--;
        }
        return val(sweepX) || val(sweepY);
    }
};